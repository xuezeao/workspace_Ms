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
	int toffset; //c�ߺ�T�ߵļ��
	int soffset;//T�����߲ο�����ļ��
	int cminvalue;//c����С��Чֵ
	int twidth;//T�߲������
	int thight;//T�߲����߶�	
	int rzout;//��ɫƫ����
	int twid;//LUT������Χ
	int sexp;//�ع�ֵ
	int tvalue;//�������ֵ
	int ovalue;//���lut����ֵ
	unsigned char *pimg;//yuvͼ��������ָ��
	char icmd;
}__attribute__((packed)) ROPTION, *PROPTION;

typedef struct tagCRVALUE {
	int ivalue; //����ԭʼֵ
	int ovalue;//���Ŀ��ֵ
}__attribute__((packed)) CRVALUE, *PCRVALUE;

struct buffer {
        void *                  start;
        size_t                  length;
};

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef long LONG;
//�����߶�λ��Ϣ���ݽṹ
typedef struct tagPOSITION {
        int startx;//��ʼx����
        int starty;//��ʼy����
	int endx;//����x����
        int endy;//����y����
	char ifen;//�����Ƿ���Ч���
}__attribute__((packed)) POSITION, *PPOSITION;

//BMP�ļ�ͷ���ݽṹ
typedef struct tagBITMAPFILEHEADER {
  WORD  bfType;
  DWORD bfSize;
  WORD  bfReserved1;
  WORD  bfReserved2;
  DWORD bfOffBits;
}__attribute__((packed)) BITMAPFILEHEADER, *PBITMAPFILEHEADER;
//BMP��Ϣͷ���ݽṹ
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
