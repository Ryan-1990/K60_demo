#ifndef __OV7725_H
#define __OV7725_H 

#include "common.h"	   
 

#define FIFO_CS_H()     PTE26_OUT=1	  
#define FIFO_CS_L()     PTE26_OUT=0	  /*拉低使FIFO输出使能*/

#define FIFO_WRST_H()   PTB3_OUT=1	  /*拉高允许FIFO写(数据from摄像头)指针运动 */
#define FIFO_WRST_L()   PTB3_OUT=0	  /*拉低使FIFO写(数据from摄像头)指针复位*/

#define FIFO_RRST_H()   PTE25_OUT=1 	  /*拉高允许FIFO读(数据从FIFO输出)指针运动 */
#define FIFO_RRST_L()   PTE25_OUT=0	  /*拉低使FIFO读(数据从FIFO输出)指针复位 */

#define FIFO_RCLK_H()   PTA14_OUT=1  
#define FIFO_RCLK_L()   PTA14_OUT=0 	  /*FIFO输出数据时钟*/

#define FIFO_WE_H()     PTB2_OUT=1	  /*拉高使FIFO写允许*/
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























