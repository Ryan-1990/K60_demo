/******************************************************************************\
*  Copyright (C) 2013-2014 Nan Li, Tianjin University 
*  ALL RIGHTS RESERVED
*  Filename: Init.c
*  Version: 1.0 
*  Author: Nan Li
\******************************************************************************/

#include  "include.h"


u8 DMA_BUFF[128];  //DMA传输缓存

/****************************************
* 通用IO的初始化
* GPO / GPI
\***************************************/
void GPIO_Init(void)
{
  //gpio_init (PORTB,0,GPI,0); 
  //gpio_init (PORTC,18,GPO,1);
}

/****************************************
* IO输入捕捉中断初始化
* zero_down , //低电平触发，内部下拉
* rising_down , //上升沿触发，内部下拉
* falling_down , //下降沿触发，内部下拉
* either_down , //跳变沿触发，内部下拉
* one_down , //高电平触发，内部下拉
* zero_up , //低电平触发，内部上拉
* rising_up , //上升沿触发，内部上拉
* falling_up , //下降沿触发，内部上拉
* either_up , //跳变沿触发，内部上拉
* one_up //高电平触发，内部上拉
\***************************************/
void EXTI_Init(void)
{
  exti_init(PORTB,9,falling_up);  //right
  exti_init(PORTB,10,falling_up); //down
  exti_init(PORTB,18,falling_up); //left
  exti_init(PORTB,19,falling_up); //up
  exti_init(PORTB,20,falling_up); //ok
}

/****************************************
* FTM输入捕捉中断初始化
* Rising             //上升沿捕捉
* Falling            //下降沿捕捉
* Rising_or_Falling  //跳变沿捕捉
\***************************************/
void FTM_Init(void)
{
  FTM_Input_init(FTM0,CH0,Rising); //初始化 FTM 输入捕捉模式，通道 0 上升沿触发
                                   //FTM0_CH0 对应 PTC1 口
}

/****************************************
* 串口初始化
\***************************************/
void UART_Init(void)
{
  uart_init(UART0, 57600);
}

/****************************************
* ADC初始化
\***************************************/
void ADC_Init(void)
{
  adc_init(ADC1,SE4a); //初始化 ADC1_SE4a ,从 adc.h 里的表格就可以看到 ADC1_SE4a 对应为 PTE0
}

/****************************************
* DAC初始化
* VREF_OUT    //内部参考电压，1.2v
* VDDA        //3.3v
\***************************************/
void DAC_Init(void)
{
  dac_once_init(DAC0,VDDA);   //初始化 DAC0
}

/****************************************
* PWM初始化
\***************************************/
void PWM_Init(void)
{
  FTM_PWM_init(FTM0,CH0,100,50); //初始化 FTM0_CH0 输出频率为 100HZ,占空比为 50%的 PWM
                                  //FTM0_CH0 对应 PTC1 口
}

/****************************************
* PIT定时器初始化
\***************************************/
void PIT_Init(void)
{
  //pit_init_ms(PIT0,1); //初始化 PIT0，定时时间为： 1ms
  //pit_init_us(PIT0,1); //初始化 PIT0，定时时间为： 1us
  pit_init_ms(PIT1,1000); //初始化 PIT1，定时时间为： 1000ms
}

/****************************************
* LPTMR脉冲计数初始化
* LPT0_ALT1   // PTA19
* LPT0_ALT2   // PTC5
* LPT_Rising     //上升沿触发
* LPT_Falling    //下降沿触发
\***************************************/
void LPT_Init(void)
{
  lptmr_counter_init(LPT0_ALT2,100,2,LPT_Rising);    //初始化脉冲计数器，用 LPT0_ALT2，即 PTC5 输入，
                                                     //每隔 100 产生中断，延时 2 个时钟滤波，上升沿触发
}

/****************************************
* DMA初始化
* LPT0_ALT1   // PTA19
* LPT0_ALT2   // PTC5
* LPT_Rising     //上升沿触发
* LPT_Falling    //下降沿触发
\***************************************/
void DMA_Init(void)
{
  // DMA 通道 0 初始化，PTA19 上升沿触发 DMA 传输，源地址为 PTD_BYTE0_IN，目的地址为：DMA_BUFF
  // 每次传输 1Byte，传输 4 次后停止传输 触发中断，恢复目的地址
  DMA_PORTx2BUFF_Init (DMA_CH0,(void *)&PTD_BYTE0_IN,DMA_BUFF,PTA19,DMA_BYTE1,4,DMA_rising);
}

/****************************************
* Flash初始化
\***************************************/
void Flash_Init(void)
{
  flash_init();
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/****************************************
* 上电初始化函数(按首字母排序)
\***************************************/
void Init(void)
{
  //ADC_Init();  //AD初始化
  //DAC_Init();  //DA初始化
  //DMA_Init();  //DMA初始化
  EXTI_Init(); //GPIO外部中断初始化
  //Flash_Init();//Flash初始化
  //FTM_Init();  //FTM输入捕捉中断初始化
  //GPIO_Init(); //GPIO初始化
  //LED_init();  //LED初始化
  //LPT_Init();  //LPTMR脉冲计数初始化
  PIT_Init();  //PIT定时器中断初始化
  //PWM_Init();  //PWM初始化
  //UART_Init(); //串口初始化
}