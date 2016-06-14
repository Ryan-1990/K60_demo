#include "SCCB.h"
#include "delay.h"
#include "gpio.h"

#define DEV_ADR  ADDR_OV7725 			 /*设备地址定义*/

/********************************************************************
 * 函数名：SCCB_Configuration
 * 描述  ：SCCB管脚配置
 * 输入  ：无
 * 输出  ：无
 * 注意  ：无        
 ********************************************************************/
void SCCB_GPIO_Configuration(void)
{
  /* SCL(PTA0)、SDA(PTA1)管脚配置 */
  SCL_OUT;
  SDA_OUT;
  
  /* PA17 用于控制1w的补光灯，低电平点亮 */
  gpio_init (PORTA,17,GPO,1);
  LED_OFF;
}


/********************************************************************
 * 函数名：SCCB_Start
 * 描述  ：SCCB起始信号
 * 输入  ：无
 * 输出  ：无
 * 注意  ：内部调用        
 ********************************************************************/
static void SCCB_Start(void)
{
  SDA_OUT;
  SCL_H;
  SDA_H;
  DLY_us(1);
  SDA_L;
  DLY_us(1);
  SCL_L;
}



/********************************************************************
 * 函数名：SCCB_Stop
 * 描述  ：SCCB停止信号
 * 输入  ：无
 * 输出  ：无
 * 注意  ：内部调用        
 ********************************************************************/
static void SCCB_Stop(void)
{
  SDA_OUT;
  SCL_L;
  SDA_L;
  DLY_us(1);
  SCL_H;
  SDA_H;
  DLY_us(1);
}



/********************************************************************
 * 函数名：SCCB_Ack
 * 描述  ：SCCB应答方式
 * 输入  ：无
 * 输出  ：无
 * 注意  ：内部调用        
 ********************************************************************/
static void SCCB_Ack(void)
{	
  SCL_L;
  SDA_OUT;
  SDA_L;
  DLY_us(5);
  SCL_H;
  DLY_us(5);
  SCL_L;
}



/********************************************************************
 * 函数名：SCCB_NoAck
 * 描述  ：SCCB 无应答方式
 * 输入  ：无
 * 输出  ：无
 * 注意  ：内部调用        
 ********************************************************************/
static void SCCB_NoAck(void)
{	
  SCL_L;
  SDA_OUT;
  SDA_H;
  DLY_us(5);
  SCL_H;
  DLY_us(5);
  SCL_L;
}




/********************************************************************
 * 函数名：SCCB_WaitAck
 * 描述  ：SCCB 等待应答
 * 输入  ：无
 * 输出  ：返回为:=1有ACK,=0无ACK
 * 注意  ：内部调用        
 ********************************************************************/
static int SCCB_WaitAck(void) 	
{
  SDA_OUT;
  SCL_L;
  DLY_us(2);
  SDA_H;			
  DLY_us(2);
  SCL_H;
  DLY_us(2);
  SDA_IN;
  if(SDA_read)
  {
    SCL_L;
    return 0;
  }
  SCL_L;
  return 1;
}



 /*******************************************************************
 * 函数名：SCCB_SendByte
 * 描述  ：数据从高位到低位
 * 输入  ：SendByte: 发送的数据
 * 输出  ：无
 * 注意  ：内部调用        
 *********************************************************************/
static void SCCB_SendByte(u8 SendByte) 
{
  u8 i=8;
  SDA_OUT;
  while(i--)
  {
    SCL_L;
    DLY_us(5);
    if(SendByte&0x80)
      SDA_H;  
    else 
      SDA_L;   
    SendByte<<=1;
    DLY_us(5);
    SCL_H;
    DLY_us(5);
  }
  SCL_L;
}




 /******************************************************************
 * 函数名：SCCB_ReceiveByte
 * 描述  ：数据从高位到低位
 * 输入  ：无
 * 输出  ：SCCB总线返回的数据
 * 注意  ：内部调用        
 *******************************************************************/
int SCCB_ReceiveByte(void)  
{ 
  u8 i=8;
  u8 ReceiveByte=0;

  SDA_IN;
  while(i--)
  {
    SCL_L;
    DLY_us(5);
    SCL_H;
    DLY_us(5);
    ReceiveByte<<=1;  
    if(SDA_read)
      ReceiveByte++;
  }
  SCL_L;
  return ReceiveByte;
}





 /*****************************************************************************************
 * 函数名：SCCB_WriteByte
 * 描述  ：写一字节数据
 * 输入  ：- WriteAddress: 待写入地址 	- SendByte: 待写入数据	- DeviceAddress: 器件类型
 * 输出  ：返回为:=1成功写入,=0失败
 * 注意  ：无        
 *****************************************************************************************/           
int SCCB_WriteByte( u16 WriteAddress , u8 SendByte )
{		
  SCCB_Start();
  SCCB_SendByte( DEV_ADR );                    /* 器件地址 */
  if( !SCCB_WaitAck() )
  {
    SCCB_Stop(); 
    return 0;
  }
  SCCB_SendByte((u8)(WriteAddress & 0x00FF));   /* 设置低起始地址 */      
  SCCB_WaitAck();	
  SCCB_SendByte(SendByte);
  SCCB_WaitAck();   
  SCCB_Stop(); 
  return 1;
}									 




/******************************************************************************************************************
 * 函数名：SCCB_ReadByte
 * 描述  ：读取一串数据
 * 输入  ：- pBuffer: 存放读出数据 	- length: 待读出长度	- ReadAddress: 待读出地址		 - DeviceAddress: 器件类型
 * 输出  ：返回为:=1成功读入,=0失败
 * 注意  ：无        
 **********************************************************************************************************************/           
int SCCB_ReadByte(u8* pBuffer,   u16 length,   u8 ReadAddress)
{	
  SCCB_Start();
  SCCB_SendByte( DEV_ADR );         /* 器件地址 */
  if( !SCCB_WaitAck() )
  {
    SCCB_Stop(); 
    return 0;
  }
  SCCB_SendByte( ReadAddress );           /* 设置低起始地址 */      
  SCCB_WaitAck();	
  SCCB_Stop(); 
      
  SCCB_Start();
  SCCB_SendByte( DEV_ADR + 1 );               /* 器件地址 */ 
  if(!SCCB_WaitAck())
  {
    SCCB_Stop(); 
    return 0;
  }
  while(length)
  {
    *pBuffer = SCCB_ReceiveByte();
    if(length == 1)
    {
      SCCB_NoAck();
    }
    else
    {
      SCCB_Ack(); 
    }
    pBuffer++;
    length--;
  }
  SCCB_Stop();
  return 1;
}




