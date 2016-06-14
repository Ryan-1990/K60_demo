//#ifndef __INCLUDE_H__
//#define __INCLUDE_H__


#include  "common.h"

extern u8 mystr[20];  //OLED��ʾ����
extern u8 DMA_BUFF[128];  //DMA���仺��


/***************** ucos ר�� *****************/
#define UCOS_EN     1u      //0Ϊ��ֹuC/OS������0������uC/OS
#if UCOS_EN > 0u
#include  "ucos_ii.h"  		//uC/OS-IIϵͳ����ͷ�ļ�
#include  "app.h"			//�û�������

#endif  //if  UCOS_EN > 0

/*
 * Include �û��Զ����ͷ�ļ�
 */
#include  "adc.h"       //ADCģ��
#include  "dac.h"       //DACģ��
#include  "delay.h"     //��ʱ
#include  "dma.h"       //DMA
#include  "exti.h"      //EXTI�ⲿGPIO�ж�
#include  "ff.h"        //FatFs�ļ�ϵͳ
#include  "flash.h"     //Flash
#include  "FTM.h"       //FTM
#include  "gpio.h"      //IO
#include  "Init.h"      //��ʼ��
#include  "LCD.h"       //TFT��Ļ
#include  "LED.h"       //������LED
#include  "lptmr.h"     //�͹��Ķ�ʱ��(��ʱ)
#include  "NRF24L01.h"
#include  "OLED.h"      //OLED��Ļ
#include  "OV7725.h"      //����ͷ
#include  "PIT.h"       //��ʱ��
//#include  "rtc.h"       //rtc
#include  "spi.h"
#include  "uart.h"      //����

//#endif  //__INCLUDE_H__
