
//从YUV数据重建出R(Red)
unsigned char GetYUVR(int nY,int nU,int nV)
{
	int nR;    //V=nV-128
	nR = nY + (nV-128)+((nV-128)*103>>8);// v + ((v * 103) >> 8);

	//溢出检测
	if( nR > 255 )
		nR = 255;
	if( nR < 0 )
		nR = 0;   
	return nR;
}
//从YUV数据重建出G(Green)
unsigned char GetYUVG(int nY,int nU,int nV)
{
	int nG;    //U = nU-128
	nG = nY - (((nU-128)*88>>8)+((nV-128)*183>>8));//((u * 88) >> 8) +((v * 183) >> 8);

	//溢出检测
	if( nG > 255 )
		nG = 255;
	if( nG < 0 )
		nG = 0;   
	return nG;   
}
//从YUV数据重建出B(Blue)
unsigned char GetYUVB(int nY,int nU,int nV)
{
	int nB;
	nB = nY + (nU-128)+((nU-128)*198>>8);//u +( (u*198) >> 8);

	//溢出检测
	if( nB > 255 )
		nB = 255;
	if( nB < 0 )
		nB = 0;       
	return nB;
}

/**************************************************************************
**************************************************************************/
int YUV2RGB(unsigned char* pYUV,unsigned char* pRGB,int width,int height)
{
	//参数检测
	if(pYUV == 0) return -1;
	if(pRGB == 0) return -1;
	if((width <= 0) || (width >= 5000)) return -2;
	if((height<= 0) || (height>= 5000)) return -2;


	int i = 0;
	int j = 0;
	for ( i=0;i<height;i++)
	{
		for (j=0;j<width*2;j+=4)
		{
			int y1,u,y2,v;
			unsigned char r,g,b;
			y1 = pYUV[(height-i-1)*width*2+j+0];
			u  = pYUV[(height-i-1)*width*2+j+1];
			y2 = pYUV[(height-i-1)*width*2+j+2];
			v  = pYUV[(height-i-1)*width*2+j+3];

			r = GetYUVR(y1,u,v);
			g = GetYUVG(y1,u,v);
			b = GetYUVB(y1,u,v);				

			*pRGB++ = b; // first pixel
			*pRGB++ = g; // first pixel
			*pRGB++ = r; // first pixel

			r = GetYUVR(y2,u,v);
			g = GetYUVG(y2,u,v);
			b = GetYUVB(y2,u,v);				

			*pRGB++ = b; // second pixel
			*pRGB++ = g; // second pixel
			*pRGB++ = r; // second pixel
		}
	}

	return 0;
}
/**************************************************************************
**************************************************************************/
int YUV2RGB0(unsigned char* pYUV,unsigned char* pRGB,int width,int height)
{
    //参数检测
    if(pYUV == 0) return -1;
    if(pRGB == 0) return -1;
    if((width <= 0) || (width >= 5000)) return -2;
    if((height<= 0) || (height>= 5000)) return -2;
//390 890 210 510 //500 300

    int i = 0;
    int j = 0;
    for ( i=210;i<510;i++)
    {
        for (j=390*2;j<890*2;j+=4)
        {
            int y1,u,y2,v;
            unsigned char r,g,b;
            y1 = pYUV[(height-i-1)*width*2+j+0];
            u  = pYUV[(height-i-1)*width*2+j+1];
            y2 = pYUV[(height-i-1)*width*2+j+2];
            v  = pYUV[(height-i-1)*width*2+j+3];

            r = GetYUVR(y1,u,v);
            g = GetYUVG(y1,u,v);
            b = GetYUVB(y1,u,v);

            *pRGB++ = b; // first pixel
            *pRGB++ = g; // first pixel
            *pRGB++ = r; // first pixel

            r = GetYUVR(y2,u,v);
            g = GetYUVG(y2,u,v);
            b = GetYUVB(y2,u,v);

            *pRGB++ = b; // second pixel
            *pRGB++ = g; // second pixel
            *pRGB++ = r; // second pixel
        }
    }

    return 0;
}
int YUV2RGB2(unsigned char* pYUV,unsigned char* pRGB,int width,int height)
{
//参数检测
	if(pYUV == 0) return -1;
	if(pRGB == 0) return -1;
	if((width <= 0) || (width >= 5000)) return -2;
	if((height<= 0) || (height>= 5000)) return -2;


	int i = 0;
	int j = 0;
	for ( i=0;i<height;i++)
	{
		for (j=0;j<width*2;j+=4)
		{
			int y1,u,y2,v;
			unsigned char r,g,b;
			y1 = pYUV[(height-i-1)*width*2+j+0];			
			y2 = pYUV[(height-i-1)*width*2+j+2];
			

			*pRGB++ = y1; // first pixel
			*pRGB++ = y1; // first pixel
			*pRGB++ = y1; // first pixel	

			*pRGB++ = y2; // second pixel
			*pRGB++ = y2; // second pixel
			*pRGB++ = y2; // second pixel
		}
	}
	return 0;
}
