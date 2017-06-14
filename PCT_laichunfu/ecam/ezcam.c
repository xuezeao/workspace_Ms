#include <stdio.h>
 #include<stdlib.h>
#include <fcntl.h> 
#include "inifile.h"
#include "ezsys.h"
#include<math.h>
#include <string.h>
#include <assert.h>          
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>     
#include <linux/videodev2.h>
#include <time.h>
#include <sys/stat.h>

struct buffer *         buffers         = NULL;
static unsigned int     n_buffers       = 0;

int fd = -1;
ROPTION Roption;
int Glut[img_Width*2];

/***********************************************
**功能：计算函数运行时间
**参数：struct timeval *result 输出的运行时间
**	struct timeval *x 输入的结束记时时间
**	struct timeval *y 输入的开始记时时间
***********************************************/
int tim_subtract(struct timeval *result, struct timeval *x, struct timeval *y)
{
	int nsec;
	if ( x->tv_sec > y->tv_sec )
		return   -1;
	if ((x->tv_sec==y->tv_sec) && (x->tv_usec>y->tv_usec))
		return   -1;
	result->tv_sec = ( y->tv_sec-x->tv_sec );
	result->tv_usec = ( y->tv_usec-x->tv_usec );
	if (result->tv_usec<0)
	{
		result->tv_sec--;
		result->tv_usec+=1000000;
		}
	return   0;
}
//
/***********************************************
**功能：数组快速排序法
**参数：long *a 输入输出数组指针
**	int i   待排序数组开始位置
**	int j	待排序数组结束位置
***********************************************/
void quick(long *a,int i,int j) 
{ 
	int m,n,temp; 
	int k; 
	m=i; 
	n=j; 
	k=a[(i+j)/2]; /*选取的参照*/ 
	do { 
		while(a[m]<k&&m<j) m++; /* 从左到右找比k大的元素*/ 
		while(a[n]>k&&n>i) n--; /* 从右到左找比k小的元素*/ 
		if(m<=n) { /*若找到且满足条件，则交换*/ 
			temp=a[m]; 
			a[m]=a[n]; 
			a[n]=temp; 
			m++; 
			n--; 
		} 
	}while(m<=n); 
	if(m<j) quick(a,m,j); /*运用递归*/ 
	if(n>i) quick(a,i,n); 
}

/***********************************************
**功能：统计图像区域亮度
**参数：unsigned char *yuvbuf 输入原始yuv图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	POSITION post 要统计区域的坐标信息
************************************************/
static long sumsql (unsigned char *yuvbuf,int bWidth,int bHeight,POSITION post)
{
	int i,j;
	long bsum=0;
	for(i=post.starty ;i<post.endy;i++)
	{
		for(j=post.startx ;j<post.endx;j++)
		{
			bsum+=255-(unsigned char)*(yuvbuf+i*bWidth*2+j*2);//亮度反向
		}
	}
	return bsum;
}
//
/***********************************************
**功能：在图像上画虚线框
**参数：unsigned char *yuvbuf 输入原始yuv图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	POSITION post 要画框区域的坐标信息
**	char ldump   画线的密度
***********************************************/
static int addsql (unsigned char *yuvbuf,int bWidth,int bHeight,POSITION post,char ldump)
{
	unsigned int i;
	for (i=post.startx ;i<post.endx;i+=ldump)
	{
		*(yuvbuf+post.starty*bWidth*2+i*2)=0;
		if(i%(2*ldump)==0)
		*(yuvbuf+post.endy*bWidth*2+i*2)=0;
	}
	for (i=post.starty ;i<post.endy;i+=ldump)
	{
		*(yuvbuf+i*bWidth*2+post.startx*2)=0;
		if(i%(2*ldump)==0)
		*(yuvbuf+i*bWidth*2+post.endx*2)=0;
	}
	return 0;
}
//
/***********************************************
**功能：保存BMP图像
**参数：unsigned char *rgbbuf 输入原始rgb图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	int nout     测试参考参数
**	int onum     测试数字
***********************************************/
static int savebmp (unsigned char *rgbbuf,int bWidth,int bHeight,long tout)
{	
   	BITMAPFILEHEADER file_head;
   	BITMAPINFOHEADER info_head;
 	long data_size = bWidth*bHeight*3;
        /*initialize bmp structs*/
        file_head.bfType = 0x4d42;
        file_head.bfSize = sizeof(file_head) + sizeof(info_head) + data_size;
        file_head.bfReserved1 = file_head.bfReserved2 = 0;
        file_head.bfOffBits = sizeof(file_head) + sizeof(info_head);
        
        info_head.biSize = sizeof(info_head);
        info_head.biWidth = bWidth;
        info_head.biHeight = bHeight;
        info_head.biPlanes = 1;
        info_head.biBitCount = 24;
        info_head.biCompression = 0;
        info_head.biSizeImage = 0;
        info_head.biXPelsPerMeter = 0;
        info_head.biYPelsPerMeter = 0;
        info_head.biClrUsed = 0;
        info_head.biClrImportant = 0;

	 ////////////////////////////////////
	 time_t   now;         //实例化time_t结构
	 struct   tm     *timenow;         //实例化tm结构指针
	 time(&now);
	 //time函数读取现在的时间(国际标准时间非北京时间)，然后传值给now
	 timenow = localtime(&now);
	 char savename[40] = "NULL";//生成图像名称
	 sprintf(savename,"img/%d%02d%02d%02d%02d%02d-%04d.bmp", timenow->tm_year + 1900, 
						timenow->tm_mon+1, 
						timenow->tm_mday, 
						timenow->tm_hour, 
						timenow->tm_min, 
						timenow->tm_sec,tout);

 	if(access("img",0)==-1)//access函数是查看文件是不是存在
   	{
        	if (mkdir("img",S_IRWXU|S_IRWXG|S_IRWXO))//如果不存在就用mkdir函数来创建
        	{
            		printf("creat file img failed!!!");
        	}
		chmod("img",S_IRWXU|S_IRWXG|S_IRWXO);
   	}
  //将图片其写入文件中
	FILE *img_fd;
	img_fd = fopen(savename, "w+");//图片文件名
  	fwrite(&file_head, sizeof(file_head),1,img_fd);
  	fwrite(&info_head, sizeof(info_head),1,img_fd);
     	fwrite(rgbbuf, data_size, 1, img_fd);
	printf("Capture one frame saved in %s\n", savename);
	fclose(img_fd);
	chmod(savename,S_IRWXU|S_IRWXG|S_IRWXO);
//将信息写入文件中
	return 0;
}
/***********************************************
**功能：检测测试条坐标
**参数：unsigned char *yuvbuf 输入原始yuvbuf图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	char mod     检测测试条的位置 0 在图像的左半边
                                     1 在图像的右半边
***********************************************/
POSITION scpst(unsigned char *yuvbuf,int bWidth,int bHeight,char mod)
{
	unsigned int i,j;
	int stesx,etesx;
	POSITION vpost;
	int ymax=0;
	int ymin=0x7fffffff;
	if(mod==0)//检测左边
	{
		stesx=250;//开始偏移200像素 以提高检测速度
		etesx=bWidth>>1;
	}
	else//检测右边
	{
		stesx=bWidth>>1;
		etesx=bWidth-250;//结束偏移200像素
	}
	POSITION post;
	post.ifen=0;
	int brightx[img_Width]={0};
	//统计在x轴上的投影直方图
	for (i=stesx ;i<etesx;i++)
	{
		for(j=100;j<bHeight-100;j++)
		{
			brightx[i]+=255-(unsigned char)*(yuvbuf+j*bWidth*2+i*2);
		}
	}

	//定位C线x轴坐标
	post.startx=etesx; //查找起始位置，从右边开始查
	post.endx=0;//查找结束位置，从左边开始查
	int lefttop=0;//左边线的变化最大值
	int righttop=0;//右边线的变化最大值
	for(i=stesx+1;i<etesx-1;i++)
	{
		if(brightx[i-1]-brightx[i+1]>righttop)//判断是否差值比原来的大，找到最大值就是边界
		{
			if(i<etesx && i>etesx/2)//判断是否越界
			{
				post.endx=i;
				righttop=brightx[i-1]-brightx[i+1];
			}

		}
		else if(brightx[i+1]-brightx[i-1]>lefttop)
		{
			post.startx=i;
			lefttop=brightx[i+1]-brightx[i-1];
		}
	}
//	printf("\n startx:%d endx:%d\n",post.startx,post.endx);
	int diff_postx=post.endx-post.startx;//计算测试线的宽度
	if(diff_postx<10 | diff_postx>100)//判断是否越界
	{
		post.ifen=1;//返回x方向错误标记
		return post;
	}

	int brighty[img_Width];
	for(i=0;i<img_Width;i++)brighty[i]=0;//直方图数组清0
	//统计在y轴上的投影直方图 范围缩小到上面已经检测出的x坐标范围
	for (i=0 ;i<bHeight;i++)
	{
		for (j=post.startx ;j<post.endx;j++)
		{
			brighty[i]+=255-(unsigned char)*(yuvbuf+i*bWidth*2+j*2);
		}		
	}
	//定位C线Y轴坐标
	post.starty=0;//查找起始位置，从顶部开始查
	post.endy=bHeight;//查找结束位置，从底部开始查
	int toptop=0;//顶部线的变化最大值
	int buttomtop=0;//底部线的变化最大值
//	printf("zzzzzzzzzzzzzzzz\n");
	for(i=1;i<bHeight-1;i++)
	{
		if(brighty[i-1]>brighty[i+1])
		{
			if(brighty[i-1]-brighty[i+1]>buttomtop)//判断是否差值比原来的大，找到最大值就是边界
			{
				post.endy=i;
                                buttomtop=brighty[i-1]-brighty[i+1];

			}
		}
		else
		{
			if(brighty[i+1]-brighty[i-1]>toptop)
			{
				post.starty=i;
//				printf("%d-%d-%d-%d-%d \n",toptop,brighty[i+1]-brighty[i-1],brighty[i+1],brighty[i-1],i);
				toptop=brighty[i+1]-brighty[i-1];
				
			}
		}
	}


	int diff_posty=post.endy-post.starty;
	if(diff_posty<100 | diff_posty>250)//判断是否越界
	{	
		post.ifen=2;//返回y方向错误标记
		return post;
	}
	if(righttop<5*diff_posty| lefttop<5*diff_posty)//判断上下边界幅度是否够大
	{
		post.ifen=3;
		return post;
	}
	if(buttomtop<5*diff_postx| toptop<5*diff_postx)//判断左右边界幅度是否够大
	{
		post.ifen=4;
		return post;
	}

	return post;
}
//
/***********************************************
**功能：统计图像亮度
**参数：unsigned char *imgbuf 输入原始yuvbuf图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
***********************************************/
int getavg (unsigned char* imgbuf,  int width, int height)  
{ 
	int cavg=0;
	int i,j;
	for(i=height/2-4;i<height/2+4;i++)
	{
		for(j=width/2-4;j<width/2+4;j++)
		{
			cavg+=imgbuf[i*width*2+j*2];
		}
	}
//	mwrite_profile_int("RZValue","MGAvg",cavg,"config.ini");
	return cavg/64;
} 
/***********************************************
**功能：检测C线和T线的距离
**参数：unsigned char *imgbuf 输入原始yuvbuf图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	POSITION post 要检测区域的坐标信息
***********************************************/
int decdis(unsigned char *yuvbuf,int bWidth,int bHeight,ROPTION *PRoption)
{
		int ltmp,rtmp;
		POSITION post;
		PRoption->icmd=0;
		post=scpst(yuvbuf,bWidth,bHeight,1);//定位T线位置
		
		if(post.ifen==0)
		{
			ltmp=post.startx;
			rtmp=post.endx;			
		}
		else
		{
			printf("TTTTTTTT these is no test mark!\n");//没检测到T线
			return 1;
		}
		post=scpst(yuvbuf,bWidth,bHeight,0);//定位C线位置
		if(post.ifen==0)
		{
			
			int difftmp=(ltmp+rtmp-post.startx-post.endx)>>1;
			//保存设置偏移量
			PRoption->toffset = mwrite_profile_int("Roption","Toffset",difftmp,"config.ini");
			if(PRoption->toffset==-1)
			{
				printf("write Toffset to ini file fail\n");
				return 1;
			}
			PRoption->toffset= difftmp;
			printf("write Toffset to ini file ok toffset=%d\n",PRoption->toffset);
			return 0;


		}
		else
		{
			printf("TTTTTTTT these is no STD mark!\n");//没检测到C线
			return 2;
		}
		return 0;
}
/***********************************************
**功能：自动校准初始参数
**参数：unsigned char *imgbuf 输入原始yuvbuf图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	POSITION post 要检测区域的坐标信息
***********************************************/
int autoinit(int fd ,unsigned char *yuvbuf,int bWidth,int bHeight,ROPTION *PRoption)
{
		POSITION post;
		static unsigned char cexp;
		static char apicnum=0;
		static long desum=0;
		static long tesum=0;
 		struct v4l2_control ctrl;
		ctrl.id = V4L2_CID_EXPOSURE_AUTO;//设置曝光手动模式
		ctrl.value = 1;
 		ioctl(fd, VIDIOC_S_CTRL, &ctrl);
 		ctrl.id = V4L2_CID_EXPOSURE_AUTO_PRIORITY;
 		ctrl.value = 0;
 		ioctl(fd, VIDIOC_S_CTRL, &ctrl);
 		ctrl.id = V4L2_CID_EXPOSURE_ABSOLUTE;//设置曝光值	
		post=scpst(yuvbuf,bWidth,bHeight,0);//检测测试条C判断是否非法
		if(post.ifen!=0)
		{
			apicnum=0;
			return 1;
		}
		int ttavg=getavg(yuvbuf,bWidth,bHeight);//统计图像平均亮度
		printf("ttavg=%d sexp=%d\n",ttavg,PRoption->sexp);
		if(cexp>1)cexp=0;
		if(ttavg>200 && cexp==0)
		{
			if(apicnum==2)	//每2帧调整一次
			{		
				PRoption->sexp=PRoption->sexp-1;//
				ctrl.value = PRoption->sexp;
	 			ioctl(fd, VIDIOC_S_CTRL, &ctrl);//设置曝光时间
				printf("add sexp=%d\n",PRoption->sexp);
				apicnum=0;
			}
			apicnum++;
			return -1;
		}
		else if(ttavg<200 && cexp==0)
		{
			if(apicnum==2)	
			{
				PRoption->sexp=PRoption->sexp+1;
				ctrl.value = PRoption->sexp;//
	 			ioctl(fd, VIDIOC_S_CTRL, &ctrl);
				printf("dev sexp=%d\n",PRoption->sexp);
				apicnum=0;
			}
			apicnum++;
			return -1;
		}
		else
		{
			cexp=1;
		}
		if(apicnum>10)
		{
			printf("startx:%d endx:%d starty:%d endy:%d ifen:%d\n",
				post.startx,post.endx,post.starty,post.endy,post.ifen);
			long monum=0;
			POSITION post2;
			//int centxi=((post.startx+post.endx)/2)+Roption.toffset;
			int tcentx=((post.startx+post.endx)/2)+PRoption->toffset;
			int tcenty=(post.starty+post.endy)/2;
			post2.starty=tcenty-PRoption->thight;
			post2.endy=tcenty+PRoption->thight;
			/////////////////////////////////////////////
			post2.startx=tcentx-PRoption->twidth;
			post2.endx=tcentx+PRoption->twidth;
			monum=sumsql (yuvbuf,bWidth,bHeight,post2)<<1;//测试条位置
			desum+=(monum/(PRoption->thight*PRoption->twidth));
			post2.startx=post2.startx-PRoption->soffset;
			post2.endx=post2.endx-PRoption->soffset;
			monum-=sumsql(yuvbuf,bWidth,bHeight,post2);//测试条左边
			post2.startx=post2.startx+PRoption->soffset*2;
			post2.endx=post2.endx+PRoption->soffset*2;
			monum-=sumsql(yuvbuf,bWidth,bHeight,post2);//测试条右边
			tesum+=monum;	
		}		
		if(apicnum==18)
		{
			mwrite_profile_int("RZValue","RZout",tesum/16,"config.ini");//T线差分亮度统计值
			mwrite_profile_int("RZValue","TAvg",desum,"config.ini");//T线差分亮度统计平均值
			mwrite_profile_int("RZValue","SAvg",255-desum/64,"config.ini");//T线差分亮度统计平均值反向
			mwrite_profile_int("CamSet","exp",PRoption->sexp,"config.ini");//曝光值
			PRoption->rzout=tesum/16;
			printf("write LUT to ini file ok \n");
			apicnum=0;
			PRoption->icmd=0;	
			tesum=0;		
			return 0;
		}
		apicnum++;	
		return -1;
}
//
/***********************************************
**功能：用户处理程序
**参数：int fd 设置相机标号
××	unsigned char *imgbuf 输入原始yuvbuf图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	int nout     测试参考参数
**	int onum     测试数字
***********************************************/
int prccallback(unsigned char *yuvbuf,int bWidth,int bHeight,int onum)
{
	char *img_buf;//RGB 图像缓存区
	img_buf = (char *)malloc(bWidth*bHeight*3);
	if (img_buf == NULL)
	{
		printf("malloc failed!\n");
	               return -1;
	}
	//yuv转rgb
        //YUV2RGB(yuvbuf,img_buf,bWidth,bHeight);
	//保存bmp图像
       // savebmp(img_buf,bWidth,bHeight,onum);
        YUV2RGB0(yuvbuf,img_buf,bWidth,bHeight);
        savebmp(img_buf,500,300,onum);

	free(img_buf);
	return 0;

}

/***********************************************
**功能：处理收到的一帧图像
**参数：int fd 设备句柄
××	unsigned char *imgbuf 输入原始yuvbuf图像指针
**	int bWidth   输入图像的宽度
**	int bHeight  输入图像的高度
**	ROPTION *SRoption 系统参数结构体
**	int *Glut 查找表数组指针
**      int readnum 图像编号
***********************************************/
int deal_img (int fd ,unsigned char *yuvbuf,int bWidth,int bHeight,ROPTION *PRoption,int *Glut,int picnum)
{
	static char apicnum=0;
	static long apicval[7]={0};
	printf("\n@@@@@@@@@@@@ deal_img @@@@@@@@@@@@\n");
	struct   timeval   start,stop,diff;
	gettimeofday(&start,0);
	printf("TTTTTTTT start time:%lds\n",start.tv_sec);//显示一帧图像开始处理时间
	unsigned int i,j;
	POSITION post;
//	printf("TTTTTTTT toffset=%d\n",PRoption->toffset);
//	printf("llllllll RZout=%d\n",PRoption->rzout);
	if(PRoption->icmd=='T'|PRoption->icmd=='t')//检测标准测试条定位命令
	{
		decdis(yuvbuf,bWidth,bHeight,PRoption);
                PRoption->pimg=yuvbuf;
		return 0;
	}
	else if(PRoption->icmd=='L'|PRoption->icmd=='l')//校准基础值
	{
		return autoinit(fd , yuvbuf,bWidth,bHeight,PRoption);
		//return 0;
	}
//	else//非命令，直接执行
	post=scpst(yuvbuf,bWidth,bHeight,0);//得到测试条C位置
	gettimeofday(&stop,0);
	tim_subtract(&diff,&start,&stop);
	printf("TTTTTTTT scpst  used time:%ldus\n",diff.tv_usec);//打印时间
//	printf("startx:%d endx:%d starty:%d endy:%d ifen:%d\n",
//			post.startx,post.endx,post.starty,post.endy,post.ifen);
	if(post.ifen!=0)//未检测到，直接退出
	{
		apicnum=0;
		printf("post.ifen:%d\n",post.ifen);
		return 1;		
	}
	else
	{
		long tsum=sumsql(yuvbuf,bWidth,bHeight,post);//计算C线值
		tsum=tsum/(post.endx-post.startx)/(post.endy-post.starty);
		printf("TTTTTTTT tsum=%d\n",tsum);
		if(tsum<PRoption->cminvalue)
		{			
			printf("t line is not ok!\n");
			return 4;
		}

		POSITION postT=scpst(yuvbuf,bWidth,bHeight,1);//得到测试条T位置
		printf("startx:%d endx:%d starty:%d endy:%d ifen:%d\n",
			postT.startx,postT.endx,postT.starty,postT.endy,postT.ifen);
		postT.startx+=4;
		postT.endx-=4;
//		postT.starty+=4;
//		postT.endy-=4;
//		addsql (yuvbuf,bWidth,bHeight,postT,2);//
		if(postT.ifen==0)
		{
			PRoption->toffset=(postT.startx+postT.endx-post.startx-post.endx)>>1;//自动检测c线和T线的间距
		}

		if(apicnum>=7)//超出采集张数，退出
			return 1;		
		apicnum++;
		if(apicnum<2)//检测到丢弃前面不稳定的2张
		{
			return 1;
		}
		addsql (yuvbuf,bWidth,bHeight,post,1);//画C线外框
		POSITION post2;
		//坐标移到T线位置
		post2.startx=post.startx+PRoption->toffset;
		post2.endx=post.endx+PRoption->toffset;
		post2.starty=post.starty;
		post2.endy=post.endy;
		addsql (yuvbuf,bWidth,bHeight,post2,1);//画T线外框
		//坐标移到T线计算区域
		post2.startx=((post2.startx+post2.endx)/2)-PRoption->twidth;
		post2.endx=((post2.startx+post2.endx)/2)+PRoption->twidth;
		post2.starty=((post2.starty+post2.endy)/2)-PRoption->thight;
		post2.endy=((post2.starty+post2.endy)/2)+PRoption->thight;
		long sumtest0=sumsql(yuvbuf,bWidth,bHeight,post2);//计算T线值
//		addsql (yuvbuf,bWidth,bHeight,post2,1);//
		//坐标移到T线左侧计算区域
		post2.startx=post2.startx-PRoption->soffset;
		post2.endx=post2.endx-PRoption->soffset;
		long sumtest1=sumsql(yuvbuf,bWidth,bHeight,post2);//计算T线值左侧参考区
//		addsql (yuvbuf,bWidth,bHeight,post2,1);//
		post2.startx=post2.startx+(PRoption->soffset<<1);
		post2.endx=post2.endx+(PRoption->soffset<<1);
		long sumtest2=sumsql(yuvbuf,bWidth,bHeight,post2);//计算T线值右侧参考区
//		addsql (yuvbuf,bWidth,bHeight,post2,1);//
		apicval[apicnum-2]=sumtest0-(sumtest1+sumtest2)/2;//

	}//ont out
	gettimeofday(&stop,0);
	tim_subtract(&diff,&start,&stop);
	printf("TTTTTTTT jis used time:%ldus\n",diff.tv_usec);
//	printf("post.ifen1:%d\n",post.ifen);
//	printf("startx:%d endx:%d starty:%d endy:%d ifen:%d\n",
//			post.startx,post.endx,post.starty,post.endy,post.ifen);
//////////////////////////////////////////////
	if(apicnum==7)//到第7张拍照结束
	{

		long onum=0;//apicval[1];//sumtest0-(sumtest1+sumtest2)/2;
		unsigned char text1[32] = "NULL";
		long nout=0;
		quick(apicval,0,5);

////////////////////////////////////////////////////
		onum=(apicval[1]+apicval[2]+apicval[3]+apicval[4])/4-PRoption->rzout;
		nout=onum;
                //if (nout<0) nout=0;
                if (onum < 0) onum = 0;
		onum/=(PRoption->thight*PRoption->twidth)>>1;	
		PRoption->tvalue=onum;
		onum=*(Glut+onum);
		PRoption->ovalue=onum;
		if (onum<0) onum=0;
		PRoption->pimg=yuvbuf;
		//
		
		if (PRoption->icmd=='A'||PRoption->icmd=='a')//自动检测图片编号不清0
		{
			prccallback(yuvbuf, bWidth, bHeight, onum);//保存图像
			return 0;
		}
		else
		{
			apicnum=0;
			return 0;
		}
		//return 0;
	}
	return 1;
}

/***********************************************
**功能：获取一帧数据
**参数：int fd 设备句柄
**	ROPTION *SRoption 系统参数结构体
**	int *Glut 查找表数组指针
**      int readnum 图像编号
***********************************************/ 
static int read_frame (int fd,ROPTION *PRoption,int *Glut,int readnum)
{
     struct v4l2_buffer buf;
     int res=-1;
     CLEAR (buf);
     buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     buf.memory = V4L2_MEMORY_MMAP;
     if(ioctl (fd, VIDIOC_DQBUF, &buf) == -1)
       {
          printf("VIDIOC_DQBUF failture\n"); //出列采集的帧缓冲
          return 2;//
       }
     assert (buf.index < n_buffers);
    if(readnum>3)
	{
    	 res=deal_img(fd,buffers[buf.index].start,1280,720,PRoption,Glut,readnum);
	}
     //再将其入列
     if(ioctl (fd, VIDIOC_QBUF, &buf)<0)
    {
     	printf("failture VIDIOC_QBUF\n");
	return 2;
   }
     return res;
}
int get_frame(int fd,ROPTION *PRoption,int *Glut)
{
	int readnum = 0;
	int res=-1;
	for (;;) //这一段涉及到异步IO
	{
		fd_set fds;
		struct timeval tv;
		int r;

		FD_ZERO(&fds);//将指定的文件描述符集清空
		FD_SET(fd, &fds);//在文件描述符集合中增加一个新的文件描述符


		tv.tv_sec = 0;
		tv.tv_usec = 100000;

		r = select(fd + 1, &fds, NULL, NULL, &tv);//判断是否可读（即摄像头是否准备好），tv是定时
		if (-1 == r)
		{
			if (EINTR == errno)
				continue;
			printf("select err\n");
		}
		if (0 == r)
		{
                        //fprintf(stderr, "select timeout\n");
			continue;
		}
		res=read_frame(fd,PRoption,Glut,readnum);
                //printf("zzzzzzzzzzzzzzzz  readnum=%d\n", readnum);
		int timeoutnum;
		if (PRoption->icmd=='L'||PRoption->icmd=='l') timeoutnum=200; else timeoutnum=50;
                if (res==0 || readnum>50)//检测到数据或读50张未检测到退出，并跳出循环
		{
			break;
		}		
		readnum++;
 	}
	return res;
}
/***********************************************
**功能：开始图像数据
**参数：ROPTION *SRoption 系统参数结构体
**	int *Glut 查找表数组指针
***********************************************/ 
int startuvc (int camexp)//ROPTION *PRoption,int *Glut
{

     //打开设备    
     char * dev_name = "/dev/video0";//摄像头设备名
     fd = open (dev_name, O_RDWR | O_NONBLOCK, 0);
     if(fd < 0)
       {
          printf("open %s failed\n",dev_name);
          return 1;
       }
     //设置视频捕获格式
     struct v4l2_format fmt;
     CLEAR (fmt);
     fmt.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     fmt.fmt.pix.width       = img_Width;
     fmt.fmt.pix.height      = img_Height;
     fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;
     fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    //设置图像格式
     if(ioctl (fd, VIDIOC_S_FMT, &fmt) < 0)
       {
          printf("failture VIDIOC_S_FMT\n");
	  return 1;
       }
	 struct v4l2_control ctrl;
	 ctrl.id = V4L2_CID_EXPOSURE_AUTO;//设置曝光手动模式
	 ctrl.value = 1;
	 ioctl(fd, VIDIOC_S_CTRL, &ctrl);
	 ctrl.id = V4L2_CID_EXPOSURE_AUTO_PRIORITY;
	 ctrl.value = 0;
	 ioctl(fd, VIDIOC_S_CTRL, &ctrl);
	 ctrl.id = V4L2_CID_EXPOSURE_ABSOLUTE;//设置曝光值
	 ctrl.value =camexp;// PRoption->sexp;//600
	 ioctl(fd, VIDIOC_S_CTRL, &ctrl);

///////////////////////////////////////////////////////////////////////
     //视频分配捕获内存
     struct v4l2_requestbuffers req;
     CLEAR (req);
     req.count               = 4;
     req.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     req.memory              = V4L2_MEMORY_MMAP;
 
     //申请缓冲，count是申请的数量
     if(ioctl (fd, VIDIOC_REQBUFS, &req) < 0)
       {
         printf("failture VIDIOC_REQBUFS\n");
         return 1;
        }
     if (req.count < 2)
        printf("Insufficient buffer memory\n");
      //内存中建立对应空间
      //获取缓冲帧的地址、长度
       buffers = calloc (req.count, sizeof (*buffers));//在内存的动态存储区中分配n个长度为size的连续空间，函数返回一个指向分配起始地址的指针
     if (!buffers)
       {
          fprintf (stderr, "Out of memory/n");
          return 1;
        }
  
     for (n_buffers = 0; n_buffers < req.count; ++n_buffers)
         {
           struct v4l2_buffer buf;   //驱动中的一帧
           CLEAR (buf);
           buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
           buf.memory      = V4L2_MEMORY_MMAP;
           buf.index       = n_buffers;// 要获取内核视频缓冲区的信息编号
 
           if (-1 == ioctl (fd, VIDIOC_QUERYBUF, &buf)) //映射用户空间
              {
                printf ("VIDIOC_QUERYBUF error\n");
                return 1;
              }
               buffers[n_buffers].length = buf.length; 
     // 把内核空间缓冲区映射到用户空间缓冲区
       buffers[n_buffers].start = mmap (NULL ,    //通过mmap建立映射关系
                                        buf.length,
                                        PROT_READ | PROT_WRITE ,
                                        MAP_SHARED ,
                                        fd,
                                        buf.m.offset);
 
          if (MAP_FAILED == buffers[n_buffers].start)
             {
               printf ("mmap failed\n");
            return 1;
             }
        }
//投放一个空的视频缓冲区到视频缓冲区输入队列中
//把四个缓冲帧放入队列，并启动数据流
        unsigned int i;
    // 将缓冲帧放入队列
       enum v4l2_buf_type type;
       for (i = 0; i < n_buffers; ++i)
           {
               struct v4l2_buffer buf;
               CLEAR (buf);
               buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
               buf.memory      = V4L2_MEMORY_MMAP;
               buf.index       = i; //指定要投放到视频输入队列中的内核空间视频缓冲区的编号;
 
               if (-1 == ioctl (fd, VIDIOC_QBUF, &buf))//申请到的缓冲进入列队
               printf ("VIDIOC_QBUF failed\n");
            }
    //开始捕捉图像数据  
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (-1 == ioctl (fd, VIDIOC_STREAMON, &type))
       {
          printf ("VIDIOC_STREAMON failed\n");
          return 1;
       }
    return 0;

}
int stopuvc(void)
{
   	unsigned int ii;
    	for (ii = 0; ii < n_buffers; ++ii)
   	if (-1 == munmap (buffers[ii].start, buffers[ii].length))   
       	free (buffers);
 
 /////////////////////////////////////////////////////////
	close (fd);
	printf("Camera test Done.\n");
	
	return 0;
}
/***********************************************
**功能：读取系统配置参数
**参数：ROPTION *SRoption 系统参数结构体
**	int *Glut 查找表数组指针
***********************************************/
int readcfg(ROPTION *SRoption,int *Glut)
{
	const char *file ="config.ini";
	const char *Roption = "Roption";
	//检查区域偏移量
	SRoption->toffset = mread_profile_int(Roption,"Toffset",135,file);
	if(SRoption->toffset==-1)
	{
		printf("write Toffset to ini file fail\n");
		return -1;
	}
	printf("toffset=%d\n",SRoption->toffset);
	//检查区域偏移量
	SRoption->soffset = mread_profile_int(Roption,"Soffset",60,file);
	if(SRoption->soffset==-1)
	{
		printf("write soffset to ini file fail\n");
		return -1;
	}
	printf("soffset=%d\n",SRoption->soffset);
	//检查区域宽度
	SRoption->twidth = mread_profile_int(Roption,"Twidth",18,file);
	if(SRoption->twidth==-1)
	{
		printf("write Twidth to ini file fail\n");
		return -1;
	}
	printf("twidth=%d\n",SRoption->twidth);
	//检查区域高度
	SRoption->thight = mread_profile_int(Roption,"Thight",66,file);
	if(SRoption->thight==-1)
	{
		printf("write Thight to ini file fail\n");
		return -1;
	}
	printf("thight=%d\n",SRoption->thight);

	//c线亮度最小值
	SRoption->cminvalue = mread_profile_int(Roption,"Cminvalue",100,file);
	if(SRoption->cminvalue==-1)
	{
		printf("write cminvalue to ini file fail\n");
		return -1;
	}
	printf("cminvalue=%d\n",SRoption->cminvalue);

	//检查标准差
	SRoption->rzout = mread_profile_int("RZValue","RZout",0,file);
	if(SRoption->rzout==-1)
	{
		printf("write RZout to ini file fail\n");
		return -1;
	}
	printf("rzout=%d\n",SRoption->rzout);
	//曲线矫正宽
	SRoption->twid = mread_profile_int("RZValue","Twid",100,file);
	if(SRoption->twid==-1)
	{
		printf("write Twid to ini file fail\n");
		return -1;
	}
	printf("twid=%d\n",SRoption->twid);
	//曝光值
	SRoption->sexp = mread_profile_int("CamSet","exp",160,file);
	if(SRoption->sexp==-1)
	{
		printf("write sexp to ini file fail\n");
		return -1;
	}
	printf("sexp=%d\n",SRoption->sexp);
	//读取LUT
	FILE *lut_fd;
//载入查找表
	if((lut_fd=fopen("lut.bin", "rb"))==NULL)
	{
		printf("init lut!\n");
		int i;
		for(i=0;i<img_Width*2;i++)
		{
			*(Glut+i)=i;
		}
		lut_fd = fopen("lut.bin", "w+");//图片文件名
		printf("creat lut!\n");
     		fwrite(Glut, img_Width*sizeof(int)*2, 1, lut_fd);
		printf("Capture one lut saved in lut.bin\n");
		fclose(lut_fd);
		chmod("lut.bin",S_IRWXU|S_IRWXG|S_IRWXO);
		printf("lut.bin cannot open init it \n"); 
				
	}
	else
	{
     		if(fread(Glut, img_Width*sizeof(int)*2, 1, lut_fd)!=1) { printf("fread write error\n");}
		printf("Read from lut.bin\n");
		fclose(lut_fd);
	}
	chmod("config.ini",S_IRWXU|S_IRWXG|S_IRWXO);
	return 0;
}
/***********************************************
**功能：手动矫正lut2 算法2采用分段折线法
**参数：int *Glut 查找表数组指针
**	CRVALUE *crvalu 输入值和矫正值数组
**	int crnum 数组有效值个数
***********************************************/
void CRlut(int *Glut,CRVALUE *crvalu,int crnum)
{
	int i,j;
	for(i=0;i<crnum;i++ )	
	{
//		printf("crvalu[i]=%d  crvalu[i+1]=%d \n",crvalu[i].ivalue,crvalu[i+1].ivalue);
		for(j=crvalu[i].ivalue;j<crvalu[i+1].ivalue;j++)
		{
			*(Glut+j)=(j-crvalu[i].ivalue)*(crvalu[i+1].ovalue-crvalu[i].ovalue)/(crvalu[i+1].ivalue-crvalu[i].ivalue)+crvalu[i].ovalue;
//			printf("invalue=%d  outvalue=%d \n",j,*(Glut+j));
		}
	}
	for(j;j<img_Width*2;j++ )	
	{
		*(Glut+j)=1000;
	}
	FILE *lut_fd;
	lut_fd = fopen("lut.bin", "w+");//文件名
     	fwrite(Glut, img_Width*sizeof(int)*2, 1, lut_fd);
	printf("Capture one lut saved in lut.bin\n");
	fclose(lut_fd);
	chmod("lut.bin",S_IRWXU|S_IRWXG|S_IRWXO);	
}

#if 0

/***********************************************
**功能：主程序入口
**参数：int argc 传入参数个数
**	char ** argv 传入参数指针
***********************************************/
int main (int argc,char ** argv)
{
	ROPTION Roption;
	int Glut[img_Width*2];
	Roption.icmd=0;
	//读取系统配置参数
	readcfg(&Roption,Glut);
	//初始化摄像头
	startuvc (Roption.sexp);	//&Roption,Glut

	char cmd[10] = {0};
 	while(1)
	{
		printf("please input cmd:");
 	 	scanf("%s", cmd);
 	 	printf("input is %s\n", cmd);
		switch(cmd[0])
		{
			case 'X'://生成查找表示例，ivalue是测试值，ovalue是目标值
			case 'x'://校正查找表				
				{CRVALUE crvalu[100];
				crvalu[0].ivalue=0;crvalu[0].ovalue=0;
				crvalu[1].ivalue=2;crvalu[1].ovalue=(int)((255-245)*1000/256);
				crvalu[2].ivalue=10;crvalu[2].ovalue=(255-240)*1000/256;
				crvalu[3].ivalue=16;crvalu[3].ovalue=(255-230)*1000/256;
				crvalu[4].ivalue=60;crvalu[4].ovalue=(255-216)*1000/256;
				crvalu[5].ivalue=74;crvalu[5].ovalue=(255-214)*1000/256;
				crvalu[6].ivalue=79;crvalu[6].ovalue=(255-206)*1000/256;
				crvalu[7].ivalue=103;crvalu[7].ovalue=(255-200)*1000/256;
				crvalu[8].ivalue=129;crvalu[8].ovalue=(255-195)*1000/256;
				crvalu[9].ivalue=152;crvalu[9].ovalue=(255-185)*1000/256;
				crvalu[10].ivalue=183;crvalu[10].ovalue=(255-180)*1000/256;
				crvalu[11].ivalue=213;crvalu[11].ovalue=(255-170)*1000/256;
				crvalu[12].ivalue=247;crvalu[12].ovalue=(255-165)*1000/256;
				crvalu[13].ivalue=340;crvalu[13].ovalue=(255-155)*1000/256;
				crvalu[14].ivalue=385;crvalu[14].ovalue=(255-150)*1000/256;
				crvalu[15].ivalue=463;crvalu[15].ovalue=(255-140)*1000/256;
				crvalu[16].ivalue=624;crvalu[16].ovalue=(255-120)*1000/256;
				crvalu[17].ivalue=1302;crvalu[17].ovalue=(255-50)*1000/256;
				crvalu[18].ivalue=1463;crvalu[18].ovalue=(255-0)*1000/256;
                                CRlut(Glut,crvalu,18);//19个
				}
				break;	
			case 'Q':
			case 'q':
				printf("quit the programe!\n");
				break;	
			case 'A'://自动检测
			case 'a':
				Roption.icmd=cmd[0];
				while(1)
				{			
					get_frame(fd,&Roption,Glut); 
				}
				break;
			case 'S'://触发拍照
			case 's':
				Roption.icmd=cmd[0];
				if(get_frame(fd,&Roption,Glut)==0)
				{
                                        prccallback(Roption.pimg, 1280, 720, Roption.ovalue);//保存图像
					printf("save snap image! tvalue=%d ovalue=%d\n",Roption.tvalue,Roption.ovalue);
				}
				break;
			default: //其它 如输入t或l
				Roption.icmd=cmd[0];
				get_frame(fd,&Roption,Glut); 				
				break;
		}
		if(cmd[0]=='Q'|| cmd[0]=='q') break;
 	}

	stopuvc();	

	return 0;
}
#endif
