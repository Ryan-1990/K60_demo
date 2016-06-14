#ifndef __OV7725_H
#define __OV7725_H 

#include "common.h"	   
 

#define FIFO_CS_H()     PTE26_OUT=1	  
#define FIFO_CS_L()     PTE26_OUT=0	  /*����ʹFIFO���ʹ��*/

#define FIFO_WRST_H()   PTB3_OUT=1	  /*��������FIFOд(����from����ͷ)ָ���˶� */
#define FIFO_WRST_L()   PTB3_OUT=0	  /*����ʹFIFOд(����from����ͷ)ָ�븴λ*/

#define FIFO_RRST_H()   PTE25_OUT=1 	  /*��������FIFO��(���ݴ�FIFO���)ָ���˶� */
#define FIFO_RRST_L()   PTE25_OUT=0	  /*����ʹFIFO��(���ݴ�FIFO���)ָ�븴λ */

#define FIFO_RCLK_H()   PTA14_OUT=1  
#define FIFO_RCLK_L()   PTA14_OUT=0 	  /*FIFO�������ʱ��*/

#define FIFO_WE_H()     PTB2_OUT=1	  /*����ʹFIFOд����*/
#define FIFO_WE_L()     PTB2_OUT=0  

#define OV7725_ID       0x21

extern u8 Ov7725_vsync;
extern u16 Camera_Data[128][128];

u8 Ov7725_Init(void);
void Get_Image(void);
void FIFO_Handler(void);

void VSYNC_Init(void);
void FIFO_GPIO_Configuration(void);
int  OV7725_ReadReg(u8 LCD_Reg,u16 LCD_RegValue);
int  OV7725_WriteReg(u8 LCD_Reg,u16 LCD_RegValue);

#endif























