/******************************************************************************\
*  Copyright (C) 2013-2014 Nan Li, Tianjin University 
*  ALL RIGHTS RESERVED
*  Filename: main.c
*  Version: 1.0 
*  Author: Nan Li
\******************************************************************************/


#include "include.h"

u8 mystr[20]="";
u8 Screen_Cut = 0;


void main()
{
  u8 status;	//用于判断接收/发送状态
  u8 rxbuf[32];  //接收缓冲
  u8 i=0; //用于屏幕显示行计数
  
  DisableInterrupts;	 //关总中断
  Init();
  NRF_Init();
  OLED_Init(); 
  //OLED_P6x8Str(0,0,"This is a test",0);
  Site_t site = {0,0};
  LCD_Init();
  LCD_P6x8Str(site,"System Init Success!",YELLOW,BLACK);
  DLY_ms(300);
  //SendStr (UART0,"This is a test for K60"); 
  if(Ov7725_Init())
  {
    site.y = 8;
    LCD_P6x8Str(site,"OV7725 Init Success!",CYAN,BLACK);
  }
  DLY_ms(1000);
  EnableInterrupts;	 //开总中断
  
  for(;;)
  {
    if( Ov7725_vsync == 2 )
    {
      Get_Image(); //采集图像数据
      if(!Screen_Cut) Show_Image(); //将图像显示到屏幕上
      //Send_Image(); //将图像用NRF发送出去
      Ov7725_vsync = 0;
    }
    status = NRF_ISR_Rx_Dat(rxbuf); //中断接收数据
    if(status==RX_DR) //判断接收状态
    {
      i++;
      if(i==9)
      {
        i=1;
        OLED_clear_right();
      }
      OLED_P6x8Str(64,i-1,rxbuf,0);
    }
  }
}