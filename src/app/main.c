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
  u8 status;	//�����жϽ���/����״̬
  u8 rxbuf[32];  //���ջ���
  u8 i=0; //������Ļ��ʾ�м���
  
  DisableInterrupts;	 //�����ж�
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
  EnableInterrupts;	 //�����ж�
  
  for(;;)
  {
    if( Ov7725_vsync == 2 )
    {
      Get_Image(); //�ɼ�ͼ������
      if(!Screen_Cut) Show_Image(); //��ͼ����ʾ����Ļ��
      //Send_Image(); //��ͼ����NRF���ͳ�ȥ
      Ov7725_vsync = 0;
    }
    status = NRF_ISR_Rx_Dat(rxbuf); //�жϽ�������
    if(status==RX_DR) //�жϽ���״̬
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