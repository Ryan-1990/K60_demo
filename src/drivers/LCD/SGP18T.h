
#ifndef __SGP18T_LCD_BASE_H__
#define __SGP18T_LCD_BASE_H__	

#include "common.h" 
#include "LCD.h"


/*******************接口定义******************************/
#define CS     PTE0_OUT
#define SCK    PTE1_OUT 
#define SDI    PTE2_OUT
#define A0     PTE3_OUT 
#define RESET  PTE4_OUT  


/*****************私有函数声名*********************************/

void LCD_SGP18T_init(void);									//LCD初始化

void LCD_write_command(u8 cmd);						//发送控制字

void LCD_write_para8(u8 dat);						//发送数据参数

void LCD_write_para16(u16 dat);						//发送像素显示参数

void LCD_address_rst(void);							    //DDRAM地址重置

void LCD_SetPos(u8 xs,u8 ys,u8 xe,u8 ye);	//定位显示像素位置

void LCD_display_full(u16 color);					//全屏显示某种颜色


void LCD_draw_part(u8 xs,u8 ys,u8 xe,u8 ye,u16 color_dat);
															//填充矩形区域，行起始、终止坐标，列起始、终止坐标，颜色

void LCD_draw_line(u8 xs,u8 ys,u8 xe,u8 ye,u16 color_dat);
															//画线，行起始、终止坐标，列起始、终止坐标，颜色

void LCD_draw_rectangle(u8 xs,u8 ys,u8 xe,u8 ye,u16 color_dat);
															//画矩形边框，行起始、终止坐标，列起始、终止坐标，颜色

void LCD_draw_circle(u8 x,u8 y,u8 r,u16 color_dat);
															//画圆形边框，圆心横坐标、纵坐标，半径，颜色

void LCD_draw_dot(u8 x,u8 y,u16 color_dat);	//画点，横坐标，纵坐标，颜色

void display_pic();//显示图片


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