#ifndef __SCCB_H
#define __SCCB_H

#include "common.h"

#define SCL_H         PTB0_OUT=1 
#define SCL_L         PTB0_OUT=0 
   
#define SDA_H         PTB1_OUT=1
#define SDA_L         PTB1_OUT=0 

#define SCL_OUT       gpio_init (PORTB,0,GPO,1)
#define SDA_OUT       gpio_init (PORTB,1,GPO,1)
#define SDA_IN        gpio_init (PORTB,1,GPI,0)

#define LED_ON         PTA17_OUT=0
#define LED_OFF        PTA17_OUT=1 

#define SCL_read      PTB0_IN 
#define SDA_read      PTB1_IN

#define ADDR_OV7725   0x42

void SCCB_GPIO_Configuration(void);
int SCCB_WriteByte( u16 WriteAddress , u8 SendByte);
int SCCB_ReadByte(u8* pBuffer,   u16 length,   u8 ReadAddress);

#endif 
