#include "OV7725.h"
#include "delay.h"    
#include "gpio.h"
#include "exti.h"     
#include "SCCB.h"
#include "SensorConfig.h"

#define Delay_ms  DLY_ms

u8 Ov7725_vsync=0;	 //帧同步信号
u16 Camera_Data[128][128]; //摄像头数据
extern u8 OV7725_REG_NUM;
extern Register_Info Sensor_Config[];


/************************************************
 * 函数名：FIFO_GPIO_Configuration
 * 描述  ：FIFO GPIO配置
 * 输入  ：无
 * 输出  ：无
 * 注意  ：无
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
  
  FIFO_CS_L();  //允许读
  FIFO_RRST_L();        //读指针复位
  FIFO_RCLK_L();        //至少需要一个时钟周期的跳变才能复位
  FIFO_RCLK_H();
  FIFO_RCLK_L();        //至少需要一个时钟周期的跳变才能复位
  FIFO_RCLK_H();
  FIFO_RRST_H();
  FIFO_CS_H();	//禁止读
  
  FIFO_WE_H();	//拉高使FIFO写允许
  FIFO_WRST_L(); 
  FIFO_WRST_H(); 
  FIFO_WE_L();	//禁止写FIFO
}


/************************************************
 * 函数名：VSYNC_Init
 * 描述  ：OV7725 帧同步信号中断配置
 * 输入  ：无
 * 输出  ：无
 * 注意  ：无
 ************************************************/
void VSYNC_Init(void)
{
  exti_init(PORTE,24,rising_down);
}





/************************************************
 * 函数名：Sensor_Init
 * 描述  ：Sensor初始化
 * 输入  ：无
 * 输出  ：返回1成功，返回0失败
 * 注意  ：无
 ************************************************/
u8 Ov7725_Init(void)
{
  u16 i = 0;
  u8 Sensor_IDCode = 0;
  
  FIFO_GPIO_Configuration();
  SCCB_GPIO_Configuration();
  VSYNC_Init();
  
  if( 0 == SCCB_WriteByte ( COM7, 0x80 ) ) /*复位sensor */
  {
    //DEBUG("警告:SCCB写数据错误");
    Delay_ms(50);
    return 0 ;
  }
  Delay_ms(50);
  if( 0 == SCCB_ReadByte( &Sensor_IDCode, 1, VER ) )	 /* 读取sensor ID号*/
  {        
    //DEBUG("警告:读取ID失败"); 
    return 0;
  }
  //DEBUG("Get ID success，SENSOR ID is 0x%x", Sensor_IDCode);
  //DEBUG("Config Register Number is %d ", OV7725_REG_NUM);
  if(Sensor_IDCode == OV7725_ID)
  {
    for( i = 0 ; i < OV7725_REG_NUM ; i++ )
    {
      if( 0 == SCCB_WriteByte(Sensor_Config[i].Address, Sensor_Config[i].Value) )
      {                
        //DEBUG("警告:写寄存器0x%x失败", Sensor_Config[i].Address);
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
    FIFO_WE_H();	//拉高使FIFO写允许
    FIFO_CS_H();	//禁止读
    FIFO_WRST_L();  
    FIFO_WRST_H();        
    Ov7725_vsync = 1;	
  }
  else if( Ov7725_vsync == 1 )
  {
    FIFO_WE_L(); //拉低使FIFO写暂停
    FIFO_CS_L(); //允许读
    Ov7725_vsync = 2;
  } 
}

void Get_Image(void)
{
  u16 i, j, temp;
  
  for(i = 0; i < 240; i++)
  {
    if(i>55 && i<184) //只取中间的128列数据
    {
      for(j = 0; j < 320; j++)
      {
        if(j>95 && j<224) //只取中间的128行数据
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
  FIFO_RRST_L();                                //读指针复位                                                                                
  for(i=0;i<5;i++)                
  {
    FIFO_RCLK_L();                                //至少需要一个时钟周期的跳变才能复位
    FIFO_RCLK_H();
  }
  FIFO_RRST_H();
}

