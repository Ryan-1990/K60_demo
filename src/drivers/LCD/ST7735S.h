/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,野火科技
 *     All rights reserved.
 *     技术讨论：野火初学论坛 http://www.chuxue123.com
 *
 *     除注明出处外，以下所有内容版权均属野火科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留野火科技的版权声明。
 *
 * @file       FIRE_LCD_ST7735S.h
 * @brief      LCD 函数库
 * @author     野火科技
 * @version    v5.0
 * @date       2013-09-07
 */

#ifndef _FIRE_LCD_ST7735S_H_
#define _FIRE_LCD_ST7735S_H_

#include "gpio.h"
#include "LCD.h"

//用户配置
#define ST7735S_DIR_DEFAULT     0       //定义默认方向 (0~3)

/*********************** API接口 ******************************/
//提供API接口给LCD调用

#define LCD_H                   ST7735S_get_h()                 //高
#define LCD_W                   ST7735S_get_w()                 //宽
         
#define LCD_PTLON(site,size)    LCD_ST7735S_ptlon(site,size)    //开窗
#define LCD_RAMWR()             LCD_WR_CMD(0x2C)                //写模式
#define LCD_WR_DATA(data)       do{LCD_ST7735S_WR_8DATA((u8)((data)>>8) );LCD_ST7735S_WR_8DATA( (u8)(data) );}while(0)       //写数据
#define LCD_WR_CMD(cmd)         LCD_ST7735S_WR_8CMD(cmd)        //命令
#define LCD_SET_DIR(opt)        LCD_ST7735S_dir(opt)            //方向

#define LCD_DIR                 ST7735S_get_dir()               //获取方向


//通过函数调用，速度太慢了，改成宏定义调用
//#define LCD_WR_8DATA(data)      LCD_ST7735S_wr_data(data)       //写数据
//#define LCD_WR_8CMD(cmd)        LCD_ST7735S_wr_cmd(cmd)         //命令


/********************* ST7735S内部实现 ***********************/
//LCD 的管脚定义
#define     LCD_ST7735S_WR      PTC9
#define     LCD_ST7735S_RD      PTC10
#define     LCD_ST7735S_CS      PTC11
#define     LCD_ST7735S_RS      PTC12
#define     LCD_ST7735S_RST     PTC13

//此部分需要修改初始化里的代码
#define     LCD_ST7735S_P0              PTC_B0_OUT
#define     LCD_ST7735S_PIN             PTC_B0_IN
#define     LCD_ST7735S_PDDR_OUT()      (DDRC_B0 = 0xff)
#define     LCD_ST7735S_PDDR_IN()       (DDRC_B0 = 0)


#define ST7735S_DELAY()                         //do{asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");}while(0)
#define ST7735S_DELAY_MS    DLY_ms


extern void     LCD_ST7735S_init();
extern void     LCD_ST7735S_dir(u8 option);
extern void     LCD_ST7735S_ptlon(Site_t site, Size_t size);
extern u16   ST7735S_get_h();
extern u16   ST7735S_get_w();
extern u8    ST7735S_get_dir();


extern void LCD_ST7735S_wr_data(u8 data);
extern void LCD_ST7735S_wr_cmd(u8 cmd);

#define     LCD_ST7735S_WR_OUT      PTXn_T(LCD_ST7735S_WR,OUT)
#define     LCD_ST7735S_RD_OUT      PTXn_T(LCD_ST7735S_RD,OUT)
#define     LCD_ST7735S_CS_OUT      PTXn_T(LCD_ST7735S_CS,OUT)
#define     LCD_ST7735S_RS_OUT      PTXn_T(LCD_ST7735S_RS,OUT)
#define     LCD_ST7735S_RST_OUT     PTXn_T(LCD_ST7735S_RST,OUT)

#define LCD_ST7735S_WR_8CMD(cmd)    do\
                            {\
                                LCD_ST7735S_RD_OUT=1;\
                                LCD_ST7735S_RS_OUT=0;\
                                LCD_ST7735S_CS_OUT=0;\
                                LCD_ST7735S_P0=(u8)(cmd);\
                                LCD_ST7735S_WR_OUT=0;\
                                LCD_ST7735S_WR_OUT=1;\
                                LCD_ST7735S_CS_OUT=1;\
                            }while(0)   //LCD_WR=0;LCD_WR=1;产生一个上升沿

#define LCD_ST7735S_WR_8DATA(data)  do\
                            {\
                                LCD_ST7735S_RD_OUT=1;\
                                LCD_ST7735S_RS_OUT=1;\
                                LCD_ST7735S_CS_OUT=0;\
                                LCD_ST7735S_P0=(u8)(data);\
                                LCD_ST7735S_WR_OUT=0;\
                                LCD_ST7735S_WR_OUT=1;\
                                LCD_ST7735S_CS_OUT=1;\
                            }while(0)   //LCD_WR=0;在这里写入数据到RAM


#define LCD_ST7735S_WR_DATA(data)       do{LCD_ST7735S_WR_8DATA((u8)((data)>>8) );LCD_ST7735S_WR_8DATA( (u8)(data) );}while(0)       //写数据



#endif  //_FIRE_LCD_ST7735S_H_
