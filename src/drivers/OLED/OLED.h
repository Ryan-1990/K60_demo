/******************************************************************************\
*  Copyright (C) 2012 Nan Li, Tianjin University 
*  ALL RIGHTS RESERVED
*  Filename: OLED.h
*  Version: 1.0
*  Author: Nan Li
\******************************************************************************/




#define D0  PTA15_OUT 
#define D1  PTA16_OUT
#define RST PTA13_OUT
#define DC  PTA12_OUT

/*
#define XLevelL		0x00
#define XLevelH		0x10
#define XLevel		((XLevelH&0x0F)*16+XLevelL)
#define Max_Column	128
#define Max_Row		  64
*/

#define	Brightness	0xFF 
#define X_WIDTH 128
#define Y_WIDTH 64


 
void OLED_Init(void);
void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[],unsigned char ConverseSelect);
void OLED_P14x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
void OLED_Print(unsigned char x, unsigned char y, unsigned char ch[]);
void OLED_Fill(unsigned char dat);
void OLED_clear(void);
void OLED_draw_line(unsigned int data[]);
void OLED_clear_line(unsigned int line);
void OLED_clear_all(void);
void OLED_clear_left(void);
void OLED_clear_right(void);
void OLED_Draw_Curve(unsigned char *data);