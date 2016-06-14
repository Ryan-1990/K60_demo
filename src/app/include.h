//#ifndef __INCLUDE_H__
//#define __INCLUDE_H__


#include  "common.h"

extern u8 mystr[20];  //OLED显示缓存
extern u8 DMA_BUFF[128];  //DMA传输缓存


/***************** ucos 专用 *****************/
#define UCOS_EN     1u      //0为禁止uC/OS，大于0则启动uC/OS
#if UCOS_EN > 0u
#include  "ucos_ii.h"  		//uC/OS-II系统函数头文件
#include  "app.h"			//用户任务函数

#endif  //if  UCOS_EN > 0

/*
 * Include 用户自定义的头文件
 */
#include  "adc.h"       //ADC模块
#include  "dac.h"       //DAC模块
#include  "delay.h"     //延时
#include  "dma.h"       //DMA
#include  "exti.h"      //EXTI外部GPIO中断
#include  "ff.h"        //FatFs文件系统
#include  "flash.h"     //Flash
#include  "FTM.h"       //FTM
#include  "gpio.h"      //IO
#include  "Init.h"      //初始化
#include  "LCD.h"       //TFT屏幕
#include  "LED.h"       //调试用LED
#include  "lptmr.h"     //低功耗定时器(延时)
#include  "NRF24L01.h"
#include  "OLED.h"      //OLED屏幕
#include  "OV7725.h"      //摄像头
#include  "PIT.h"       //定时器
//#include  "rtc.h"       //rtc
#include  "spi.h"
#include  "uart.h"      //串口

//#endif  //__INCLUDE_H__
