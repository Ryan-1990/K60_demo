#include "SCCB.h"
#include "delay.h"
#include "gpio.h"

#define DEV_ADR  ADDR_OV7725 			 /*�豸��ַ����*/

/********************************************************************
 * ��������SCCB_Configuration
 * ����  ��SCCB�ܽ�����
 * ����  ����
 * ���  ����
 * ע��  ����        
 ********************************************************************/
void SCCB_GPIO_Configuration(void)
{
  /* SCL(PTA0)��SDA(PTA1)�ܽ����� */
  SCL_OUT;
  SDA_OUT;
  
  /* PA17 ���ڿ���1w�Ĳ���ƣ��͵�ƽ���� */
  gpio_init (PORTA,17,GPO,1);
  LED_OFF;
}


/********************************************************************
 * ��������SCCB_Start
 * ����  ��SCCB��ʼ�ź�
 * ����  ����
 * ���  ����
 * ע��  ���ڲ�����        
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
 * ��������SCCB_Stop
 * ����  ��SCCBֹͣ�ź�
 * ����  ����
 * ���  ����
 * ע��  ���ڲ�����        
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
 * ��������SCCB_Ack
 * ����  ��SCCBӦ��ʽ
 * ����  ����
 * ���  ����
 * ע��  ���ڲ�����        
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
 * ��������SCCB_NoAck
 * ����  ��SCCB ��Ӧ��ʽ
 * ����  ����
 * ���  ����
 * ע��  ���ڲ�����        
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
 * ��������SCCB_WaitAck
 * ����  ��SCCB �ȴ�Ӧ��
 * ����  ����
 * ���  ������Ϊ:=1��ACK,=0��ACK
 * ע��  ���ڲ�����        
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
 * ��������SCCB_SendByte
 * ����  �����ݴӸ�λ����λ
 * ����  ��SendByte: ���͵�����
 * ���  ����
 * ע��  ���ڲ�����        
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
 * ��������SCCB_ReceiveByte
 * ����  �����ݴӸ�λ����λ
 * ����  ����
 * ���  ��SCCB���߷��ص�����
 * ע��  ���ڲ�����        
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
 * ��������SCCB_WriteByte
 * ����  ��дһ�ֽ�����
 * ����  ��- WriteAddress: ��д���ַ 	- SendByte: ��д������	- DeviceAddress: ��������
 * ���  ������Ϊ:=1�ɹ�д��,=0ʧ��
 * ע��  ����        
 *****************************************************************************************/           
int SCCB_WriteByte( u16 WriteAddress , u8 SendByte )
{		
  SCCB_Start();
  SCCB_SendByte( DEV_ADR );                    /* ������ַ */
  if( !SCCB_WaitAck() )
  {
    SCCB_Stop(); 
    return 0;
  }
  SCCB_SendByte((u8)(WriteAddress & 0x00FF));   /* ���õ���ʼ��ַ */      
  SCCB_WaitAck();	
  SCCB_SendByte(SendByte);
  SCCB_WaitAck();   
  SCCB_Stop(); 
  return 1;
}									 




/******************************************************************************************************************
 * ��������SCCB_ReadByte
 * ����  ����ȡһ������
 * ����  ��- pBuffer: ��Ŷ������� 	- length: ����������	- ReadAddress: ��������ַ		 - DeviceAddress: ��������
 * ���  ������Ϊ:=1�ɹ�����,=0ʧ��
 * ע��  ����        
 **********************************************************************************************************************/           
int SCCB_ReadByte(u8* pBuffer,   u16 length,   u8 ReadAddress)
{	
  SCCB_Start();
  SCCB_SendByte( DEV_ADR );         /* ������ַ */
  if( !SCCB_WaitAck() )
  {
    SCCB_Stop(); 
    return 0;
  }
  SCCB_SendByte( ReadAddress );           /* ���õ���ʼ��ַ */      
  SCCB_WaitAck();	
  SCCB_Stop(); 
      
  SCCB_Start();
  SCCB_SendByte( DEV_ADR + 1 );               /* ������ַ */ 
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




