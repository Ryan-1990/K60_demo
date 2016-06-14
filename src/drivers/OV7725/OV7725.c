#include "OV7725.h"
#include "delay.h"    
#include "gpio.h"
#include "exti.h"     
#include "SCCB.h"
#include "SensorConfig.h"

#define Delay_ms  DLY_ms

u8 Ov7725_vsync=0;	 //֡ͬ���ź�
u16 Camera_Data[128][128]; //����ͷ����
extern u8 OV7725_REG_NUM;
extern Register_Info Sensor_Config[];


/************************************************
 * ��������FIFO_GPIO_Configuration
 * ����  ��FIFO GPIO����
 * ����  ����
 * ���  ����
 * ע��  ����
 ************************************************/
void FIFO_GPIO_Configuration(void)
{
  gpio_init (PORTB,2,GPO_HDS,0);   
  gpio_init (PORTB,3,GPO_HDS,0);
  gpio_init (PORTA,14,GPO_HDS,0); 
  gpio_init (PORTE,25,GPO_HDS,0); 
  gpio_init (PORTE,26,GPO_HDS,0); 
  
  gpio_init (PORTD,0,GPI,0);  
  gpio_init (PORTD,1,GPI,0);
  gpio_init (PORTD,2,GPI,0); 
  gpio_init (PORTD,3,GPI,0); 
  gpio_init (PORTD,4,GPI,0); 
  gpio_init (PORTD,5,GPI,0); 
  gpio_init (PORTD,6,GPI,0); 
  gpio_init (PORTD,7,GPI,0); 
  
  FIFO_CS_L();  //�����
  FIFO_RRST_L();        //��ָ�븴λ
  FIFO_RCLK_L();        //������Ҫһ��ʱ�����ڵ�������ܸ�λ
  FIFO_RCLK_H();
  FIFO_RCLK_L();        //������Ҫһ��ʱ�����ڵ�������ܸ�λ
  FIFO_RCLK_H();
  FIFO_RRST_H();
  FIFO_CS_H();	//��ֹ��
  
  FIFO_WE_H();	//����ʹFIFOд����
  FIFO_WRST_L(); 
  FIFO_WRST_H(); 
  FIFO_WE_L();	//��ֹдFIFO
}


/************************************************
 * ��������VSYNC_Init
 * ����  ��OV7725 ֡ͬ���ź��ж�����
 * ����  ����
 * ���  ����
 * ע��  ����
 ************************************************/
void VSYNC_Init(void)
{
  exti_init(PORTE,24,rising_down);
}





/************************************************
 * ��������Sensor_Init
 * ����  ��Sensor��ʼ��
 * ����  ����
 * ���  ������1�ɹ�������0ʧ��
 * ע��  ����
 ************************************************/
u8 Ov7725_Init(void)
{
  u16 i = 0;
  u8 Sensor_IDCode = 0;
  
  FIFO_GPIO_Configuration();
  SCCB_GPIO_Configuration();
  VSYNC_Init();
  
  if( 0 == SCCB_WriteByte ( COM7, 0x80 ) ) /*��λsensor */
  {
    //DEBUG("����:SCCBд���ݴ���");
    Delay_ms(50);
    return 0 ;
  }
  Delay_ms(50);
  if( 0 == SCCB_ReadByte( &Sensor_IDCode, 1, VER ) )	 /* ��ȡsensor ID��*/
  {        
    //DEBUG("����:��ȡIDʧ��"); 
    return 0;
  }
  //DEBUG("Get ID success��SENSOR ID is 0x%x", Sensor_IDCode);
  //DEBUG("Config Register Number is %d ", OV7725_REG_NUM);
  if(Sensor_IDCode == OV7725_ID)
  {
    for( i = 0 ; i < OV7725_REG_NUM ; i++ )
    {
      if( 0 == SCCB_WriteByte(Sensor_Config[i].Address, Sensor_Config[i].Value) )
      {                
        //DEBUG("����:д�Ĵ���0x%xʧ��", Sensor_Config[i].Address);
        return 0;
      }
    }
  }
  else
  {
    return 0;
  }
  //DEBUG("OV7725 Register Config Success!");
  return 1;
}

void FIFO_Handler(void)
{
  if( Ov7725_vsync == 0 )
  {
    FIFO_WE_H();	//����ʹFIFOд����
    FIFO_CS_H();	//��ֹ��
    FIFO_WRST_L();  
    FIFO_WRST_H();        
    Ov7725_vsync = 1;	
  }
  else if( Ov7725_vsync == 1 )
  {
    FIFO_WE_L(); //����ʹFIFOд��ͣ
    FIFO_CS_L(); //�����
    Ov7725_vsync = 2;
  } 
}

void Get_Image(void)
{
  u16 i, j, temp;
  
  for(i = 0; i < 240; i++)
  {
    if(i>55 && i<184) //ֻȡ�м��128������
    {
      for(j = 0; j < 320; j++)
      {
        if(j>95 && j<224) //ֻȡ�м��128������
        {
          Camera_Data[i-56][j-96]=0; 
          FIFO_RCLK_L();
          FIFO_RCLK_H();
          
          Camera_Data[i-56][j-96] = GPIO_GET_8bit(PORTD,0);
          Camera_Data[i-56][j-96] <<= 8;
          FIFO_RCLK_L();
          FIFO_RCLK_H();
          Camera_Data[i-56][j-96] |= (GPIO_GET_8bit(PORTD,0));
        }
        else
        {
          FIFO_RCLK_L();
          FIFO_RCLK_H();
          
          FIFO_RCLK_L();
          FIFO_RCLK_H();
        }
      }
    }
    else
    {
      for(j = 0; j < 320; j++)
      {
        FIFO_RCLK_L();
        FIFO_RCLK_H();
        
        FIFO_RCLK_L();
        FIFO_RCLK_H();
      }
    }
  }
  /*
  for(i = 0; i < 240; i++)
  {
    for(j = 0; j < 320; j++)
    {
      FIFO_RCLK_L();
      FIFO_RCLK_H();
      temp=0; 
      temp = GPIO_GET_8bit(PORTD,0);
      FIFO_RCLK_L();
      FIFO_RCLK_H();
      temp=0; 
      temp = GPIO_GET_8bit(PORTD,0);
    }
  }
  */
  FIFO_RRST_L();                                //��ָ�븴λ                                                                                
  for(i=0;i<5;i++)                
  {
    FIFO_RCLK_L();                                //������Ҫһ��ʱ�����ڵ�������ܸ�λ
    FIFO_RCLK_H();
  }
  FIFO_RRST_H();
}

