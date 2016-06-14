/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,Ұ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�Ұ���ѧ��̳ http://www.chuxue123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����Ұ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��Ұ��Ƽ��İ�Ȩ������
 *
 * @file       FIRE_LCD.h
 * @brief      LCD ������
 * @author     Ұ��Ƽ�
 * @version    v5.0
 * @date       2013-09-02
 */

#define LCD_ILI9341     1
#define LCD_ST7735S     2       //LCD_ST7735S �� LCD_ST7735R ���һ�����Ĵ����������в�ͬ
#define LCD_ST7735R     3       //

#define USE_LCD   LCD_ST7735S             //ѡ��ʹ�õ� LCD
//#define USE_LCD   LCD_SGP18T

#include "ST7735S.h"
#include "SGP18T.h"



/******������ɫ*****/
#define RED     0XF800    //��ɫ
#define GREEN   0X07E0    //��ɫ
#define BLUE    0X001F    //��ɫ
#define	PURPLE	0xF81F    //��ɫ
#define	CYAN	0x07FF 	  //����ɫ
#define	ORANGE	0xFC08    //��ɫ
#define GRAY    0XFFE0    //��ɫ
#define BLACK   0X0000    //��ɫ
#define WHITE   0XFFFF    //��ɫ
#define YELLOW  0xFFE0    //��ɫ

#define FCOLOUR  CYAN      //����������ɫ
#define BCOLOUR  BLACK     //���屳����ɫ

//��ȡRGB��3Ԫ�أ�rgb565������16λ
#define RGB565_R(rgb565)                ((u8)(((u16)(rgb565)>>11) &0x1F))
#define RGB565_G(rgb565)                ((u8)(((u16)(rgb565)>> 5) &0x3F))
#define RGB565_B(rgb565)                ((u8)( (u16)(rgb565)      &0x1F))


#define GRAY_2_RGB565(gray)             ((u16)((((u8)(gray)>>3)<<11)|(((u8)(gray)>>2)<<5)|((u8)(gray)>>3)))

#define RGB565_2_GRAY(rgb565)           ((u8)(((RGB565_R(rgb565)*235+RGB565_G(rgb565)*613+RGB565_B(rgb565)*625)+1)>>8))  //  31*235+63*613+31*625+1  = 255*256


#define RGB565_H(rgb565)                ((u8)(((u16)(rgb565))>>8))
#define RGB565_L(rgb565)                (u8)(rgb565))

#define RGB24_RGB565(R,G,B)             ((u16)((((u8)(R)>>3)<<11)|(((u8)(G)>>2)<<5)|((u8)(B)>>3)))
#define RGB555_RGB565(rgb555)           (((((u16)(rgb555)) & (u16)(~0x1F)) << 1) |  (((u16)(rgb555)) & 0x1F))
#define BGR555_RGB565(bgr555)           ((((u16)(bgr555)<<11) & (u16)(0x1F<<11)) | (((u16)(bgr555)) & (u16)(0x1F<<5)) | (((u16)(bgr555)>>10) & (u16)(0x1F)))



//��Ҫ�ײ�ʵ�ֵļ����궨�壺
//LCD_H                         //��
//LCD_W                         //��

//LCD_INIT()                    //��ʼ��
//LCD_PTLON(site,size)          //����
//LCD_RAMWR()                   //дģʽ
//LCD_WR_DATA(data)             //д����
//LCD_WR_DATA_B(data)           //д����(���)��16λҺ����LCD_WR_DATAһ�¼��ɣ�8λҺ������˳��

//����Ϊ��ѡ
//LCD_RAMRD()                   //��ģʽ
//LCD_SET_DIR(opt)              //������ʾ����(0~3)
//LCD_DIR                       //��ȡ��ʾ����(0~3)


//����Ϊ�ڲ����ã���������ĺ궨�����
//LCD_WR_CMD(cmd)               //����
//LCD_RD_DATA()                 //������

//8λҺ��������Ҫ������Ĭ����16λ��
//LCD_WR_8CMD(cmd)               //����
//LCD_WR_8DATA(data)            //д����


//�����ֿⶨ�� Ӣ����ĸ�� ��ߡ�
#define LCD_EN_W        8
#define LCD_EN_H        16


/***************  LCD��ʼ��  ***************/

void LCD_Init(void);                                                                                    //LCD��ʼ��

/***************  LCD�滭  ***************/

extern void LCD_point          (Site_t,                                        u16 rgb565);                 //����
extern void LCD_rectangle      (Site_t, Size_t,                                u16 rgb565);                 //������
extern void LCD_P6x8Char       (Site_t,        u8 ascii,                    u16 Color, u16 bkColor);  //��ʾ6*8�ַ�
extern void LCD_P8x16Char      (Site_t,        u8 ascii,                    u16 Color, u16 bkColor);  //��ʾ8*16�ַ�
extern void LCD_P6x8Str        (Site_t,        u8 *Str,                     u16 Color, u16 bkColor);  //��ʾ6*8�ַ���
extern void LCD_P8x16Str       (Site_t,        u8 *Str,                     u16 Color, u16 bkColor);  //��ʾ8*16�ַ���


extern void LCD_Img_gray       (Site_t site, Size_t size, u8 *img);                   //��ʾ�Ҷ�ͼ��
extern void LCD_Img_gray_Z     (Site_t site, Size_t size, u8 *img, Size_t imgsize);   //��ʾ�Ҷ�ͼ��(������)

#define BINARY_BGCOLOR  WHITE       //�����ֵ��ͼ�񱳾���ɫ
#define BINARY_COLOR    BLACK       //�����ֵ��ͼ��ǰ����ɫ
extern void LCD_Img_Binary     (Site_t site, Size_t size, u8 *img);                   //��ʾ��ֵ��ͼ��
extern void LCD_Img_Binary_Z   (Site_t site, Size_t size, u8 *img, Size_t imgsize);   //��ʾ��ֵ��ͼ��(������)

extern void LCD_wave(Site_t site,Size_t size,u8 *img,u8 maxval,u16 Color ,u16 bkColor); //������ʾ����������ɫ��maxval ���ֵ��ʾ������ֵ�������������ֵ����
extern void LCD_wave_display(Site_t site,Size_t size,u8 *img,u8 maxval,u16 Color);        //������ʾ������������ɫ
extern void Show_Image(void);

