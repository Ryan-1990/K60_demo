
#ifndef __SGP18T_LCD_BASE_H__
#define __SGP18T_LCD_BASE_H__	

#include "common.h" 
#include "LCD.h"


/*******************�ӿڶ���******************************/
#define CS     PTE0_OUT
#define SCK    PTE1_OUT 
#define SDI    PTE2_OUT
#define A0     PTE3_OUT 
#define RESET  PTE4_OUT  


/*****************˽�к�������*********************************/

void LCD_SGP18T_init(void);									//LCD��ʼ��

void LCD_write_command(u8 cmd);						//���Ϳ�����

void LCD_write_para8(u8 dat);						//�������ݲ���

void LCD_write_para16(u16 dat);						//����������ʾ����

void LCD_address_rst(void);							    //DDRAM��ַ����

void LCD_SetPos(u8 xs,u8 ys,u8 xe,u8 ye);	//��λ��ʾ����λ��

void LCD_display_full(u16 color);					//ȫ����ʾĳ����ɫ


void LCD_draw_part(u8 xs,u8 ys,u8 xe,u8 ye,u16 color_dat);
															//��������������ʼ����ֹ���꣬����ʼ����ֹ���꣬��ɫ

void LCD_draw_line(u8 xs,u8 ys,u8 xe,u8 ye,u16 color_dat);
															//���ߣ�����ʼ����ֹ���꣬����ʼ����ֹ���꣬��ɫ

void LCD_draw_rectangle(u8 xs,u8 ys,u8 xe,u8 ye,u16 color_dat);
															//�����α߿�����ʼ����ֹ���꣬����ʼ����ֹ���꣬��ɫ

void LCD_draw_circle(u8 x,u8 y,u8 r,u16 color_dat);
															//��Բ�α߿�Բ�ĺ����ꡢ�����꣬�뾶����ɫ

void LCD_draw_dot(u8 x,u8 y,u16 color_dat);	//���㣬�����꣬�����꣬��ɫ

void display_pic();//��ʾͼƬ


void LCD_P8X16(u8 x, u8 y, u8 c_dat,u16 word_color,u16 back_color);

void LCD_P8X16Str(u8 x, u8 y, u8 *s_dat,u16 word_color,u16 back_color);

void LCD_LCD_P6X8(u8 x, u8 y, u8 c_dat,u16 word_color,u16 back_color);

void LCD_P6X8Str(u8 x, u8 y, u8 *s_dat,u16 word_color,u16 back_color);

void LCD_P6X8NUM(u8 x, u8 y, u16 num, u8 num_bit,u16 word_color,u16 back_color);

void LCD_P8X8(u8 x, u8 y, u8 c_dat,u16 word_color,u16 back_color);

void LCD_P8X8Str(u8 x, u8 y, u8 *s_dat,u16 word_color,u16 back_color);

void LCD_P8X8NUM(u8 x, u8 y, u16 num, u8 num_bit,u16 word_color,u16 back_color);

void LCD_P16x16Str(unsigned char x,unsigned char y,u8 *s_dat,u16 word_color,u16 back_color);
void LCD_P16x12Str(unsigned char x,unsigned char y,u8 *s_dat,u16 word_color,u16 back_color);
void show_pic(u8 xs,u8 ys,u8 xe,u8 ye,u8 pic[]);

#endif /*SGP18T_ILI9163B.h*/