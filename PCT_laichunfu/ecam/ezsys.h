#ifndef _EZSYS_H
#define _EZSYS_H 1

#ifdef __cplusplus
extern "C"
{
#endif

#define img_Width 1280
#define img_Height 720
#define CLEAR(x) memset (&(x), 0, sizeof (x))

//#define exttrig

typedef struct tagROPTION {
	int toffset; //c线和T线的间距
	int soffset;//T线两边参考区域的间距
	int cminvalue;//c线最小有效值
	int twidth;//T线测量宽度
	int thight;//T线测量高度	
	int rzout;//底色偏移量
	int twid;//LUT修正范围
	int sexp;//曝光值
	int tvalue;//结果测试值
	int ovalue;//结果lut修正值
	unsigned char *pimg;//yuv图像数据区指针
	char icmd;
}__attribute__((packed)) ROPTION, *PROPTION;

typedef struct tagCRVALUE {
	int ivalue; //输入原始值
	int ovalue;//输出目标值
}__attribute__((packed)) CRVALUE, *PCRVALUE;

struct buffer {
        void *                  start;
        size_t                  length;
};

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;
//测试线定位信息数据结构
typedef struct tagPOSITION {
        int startx;//开始x坐标
        int starty;//开始y坐标
	int endx;//结束x坐标
        int endy;//结束y坐标
	char ifen;//坐标是否有效标记
}__attribute__((packed)) POSITION, *PPOSITION;

//BMP文件头数据结构
typedef struct tagBITMAPFILEHEADER {
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
}__attribute__((packed)) BITMAPFILEHEADER, *PBITMAPFILEHEADER;
//BMP信息头数据结构
typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
}__attribute__((packed)) BITMAPINFOHEADER, *PBITMAPINFOHEADER;

extern ROPTION Roption;
extern int Glut[img_Width*2];
extern int fd;

int tim_subtract(struct timeval *result, struct timeval *x, struct timeval *y);
void quick(long *a,int i,int j) ;
POSITION scpst(unsigned char *yuvbuf,int bWidth,int bHeight,char mod);
int getavg (unsigned char* imgbuf,  int width, int height);
int decdis(unsigned char *yuvbuf,int bWidth,int bHeight,ROPTION *PRoption);
int autoinit(int fd ,unsigned char *yuvbuf,int bWidth,int bHeight,ROPTION *PRoption);
int prccallback(unsigned char *yuvbuf,int bWidth,int bHeight,int onum);
int deal_img (int fd ,unsigned char *yuvbuf,int bWidth,int bHeight,ROPTION *PRoption,int *Glut,int picnum);
int YUV2RGB0(unsigned char* pYUV,unsigned char* pRGB,int width,int height);
extern int get_frame(int fd,ROPTION *PRoption,int *Glut);
extern int startuvc (int camexp);
extern int stopuvc(void);
extern int readcfg(ROPTION *SRoption,int *Glut);
extern void CRlut(int *Glut,CRVALUE *crvalu,int crnum);
#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif 
