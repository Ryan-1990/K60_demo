/******************************************************************************\
*  Copyright (C) 2013-2014 Nan Li, Tianjin University 
*  ALL RIGHTS RESERVED
*  Filename: Init.c
*  Version: 1.0 
*  Author: Nan Li
\******************************************************************************/

#include  "include.h"


u8 DMA_BUFF[128];  //DMA���仺��

/****************************************
* ͨ��IO�ĳ�ʼ��
* GPO / GPI
\***************************************/
void GPIO_Init(void)
{
  //gpio_init (PORTB,0,GPI,0); 
  //gpio_init (PORTC,18,GPO,1);
}

/****************************************
* IO���벶׽�жϳ�ʼ��
* zero_down , //�͵�ƽ�������ڲ�����
* rising_down , //�����ش������ڲ�����
* falling_down , //�½��ش������ڲ�����
* either_down , //�����ش������ڲ�����
* one_down , //�ߵ�ƽ�������ڲ�����
* zero_up , //�͵�ƽ�������ڲ�����
* rising_up , //�����ش������ڲ�����
* falling_up , //�½��ش������ڲ�����
* either_up , //�����ش������ڲ�����
* one_up //�ߵ�ƽ�������ڲ�����
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
* FTM���벶׽�жϳ�ʼ��
* Rising             //�����ز�׽
* Falling            //�½��ز�׽
* Rising_or_Falling  //�����ز�׽
\***************************************/
void FTM_Init(void)
{
  FTM_Input_init(FTM0,CH0,Rising); //��ʼ�� FTM ���벶׽ģʽ��ͨ�� 0 �����ش���
                                   //FTM0_CH0 ��Ӧ PTC1 ��
}

/****************************************
* ���ڳ�ʼ��
\***************************************/
void UART_Init(void)
{
  uart_init(UART0, 57600);
}

/****************************************
* ADC��ʼ��
\***************************************/
void ADC_Init(void)
{
  adc_init(ADC1,SE4a); //��ʼ�� ADC1_SE4a ,�� adc.h ��ı��Ϳ��Կ��� ADC1_SE4a ��ӦΪ PTE0
}

/****************************************
* DAC��ʼ��
* VREF_OUT    //�ڲ��ο���ѹ��1.2v
* VDDA        //3.3v
\***************************************/
void DAC_Init(void)
{
  dac_once_init(DAC0,VDDA);   //��ʼ�� DAC0
}

/****************************************
* PWM��ʼ��
\***************************************/
void PWM_Init(void)
{
  FTM_PWM_init(FTM0,CH0,100,50); //��ʼ�� FTM0_CH0 ���Ƶ��Ϊ 100HZ,ռ�ձ�Ϊ 50%�� PWM
                                  //FTM0_CH0 ��Ӧ PTC1 ��
}

/****************************************
* PIT��ʱ����ʼ��
\***************************************/
void PIT_Init(void)
{
  //pit_init_ms(PIT0,1); //��ʼ�� PIT0����ʱʱ��Ϊ�� 1ms
  //pit_init_us(PIT0,1); //��ʼ�� PIT0����ʱʱ��Ϊ�� 1us
  pit_init_ms(PIT1,1000); //��ʼ�� PIT1����ʱʱ��Ϊ�� 1000ms
}

/****************************************
* LPTMR���������ʼ��
* LPT0_ALT1   // PTA19
* LPT0_ALT2   // PTC5
* LPT_Rising     //�����ش���
* LPT_Falling    //�½��ش���
\***************************************/
void LPT_Init(void)
{
  lptmr_counter_init(LPT0_ALT2,100,2,LPT_Rising);    //��ʼ��������������� LPT0_ALT2���� PTC5 ���룬
                                                     //ÿ�� 100 �����жϣ���ʱ 2 ��ʱ���˲��������ش���
}

/****************************************
* DMA��ʼ��
* LPT0_ALT1   // PTA19
* LPT0_ALT2   // PTC5
* LPT_Rising     //�����ش���
* LPT_Falling    //�½��ش���
\***************************************/
void DMA_Init(void)
{
  // DMA ͨ�� 0 ��ʼ����PTA19 �����ش��� DMA ���䣬Դ��ַΪ PTD_BYTE0_IN��Ŀ�ĵ�ַΪ��DMA_BUFF
  // ÿ�δ��� 1Byte������ 4 �κ�ֹͣ���� �����жϣ��ָ�Ŀ�ĵ�ַ
  DMA_PORTx2BUFF_Init (DMA_CH0,(void *)&PTD_BYTE0_IN,DMA_BUFF,PTA19,DMA_BYTE1,4,DMA_rising);
}

/****************************************
* Flash��ʼ��
\***************************************/
void Flash_Init(void)
{
  flash_init();
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/****************************************
* �ϵ��ʼ������(������ĸ����)
\***************************************/
void Init(void)
{
  //ADC_Init();  //AD��ʼ��
  //DAC_Init();  //DA��ʼ��
  //DMA_Init();  //DMA��ʼ��
  EXTI_Init(); //GPIO�ⲿ�жϳ�ʼ��
  //Flash_Init();//Flash��ʼ��
  //FTM_Init();  //FTM���벶׽�жϳ�ʼ��
  //GPIO_Init(); //GPIO��ʼ��
  //LED_init();  //LED��ʼ��
  //LPT_Init();  //LPTMR���������ʼ��
  PIT_Init();  //PIT��ʱ���жϳ�ʼ��
  //PWM_Init();  //PWM��ʼ��
  //UART_Init(); //���ڳ�ʼ��
}