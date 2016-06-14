/******************************************************************************\
*  Copyright (C) 2013-2014 Nan Li, Tianjin University 
*  ALL RIGHTS RESERVED
*  Filename: isr.c 
*  Version: 1.0 
*  Author: Nan Li
\******************************************************************************/


#include "isr.h"

extern u8 Screen_Cut;

/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：USART1_IRQHandler
*  功能说明：串口1 中断 接收 服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-14    已测试
*  备    注：
*************************************************************************/
void USART1_IRQHandler(void)
{
  uint8 ch;

  DisableInterrupts;		    //关总中断

  //接收一个字节数据并回发
  ch=uart_getchar (UART1);        //接收到一个数据
  uart_sendStr  (UART1,"\n你发送的数据为：");
  uart_putchar (UART1,ch);        //就发送出去

  EnableInterrupts;		    //开总中断
}



/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：SysTick_Handler
*  功能说明：系统滴答定时器中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-18    已测试
*  备    注：ucos里用得到
*************************************************************************/
void SysTick_Handler(void)
{
//  OSIntEnter();
//  OSTimeTick();
//  OSIntExit();
}


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：HardFault_Handler
*  功能说明：硬件上访中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-4    已测试
*  备    注：可以用LED闪烁来指示发生了硬件上访
*************************************************************************/
void HardFault_Handler(void)
{
  while (1)
  {
    printf("\n****硬件上访错误!!!*****\r\n\n");
  }
}

/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：PendSV_Handler
*  功能说明：PendSV（可悬起系统调用）中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-15    已测试
*  备    注：uC/OS用来切换任务
*************************************************************************/
void PendSV_Handler(void)
{
  
}


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：DMA_CH0_Handler
*  功能说明：DMA通道0的中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-3-18    已测试
*  备    注：
*************************************************************************/
void DMA_CH0_Handler(void)
{
  DisableInterrupts;
  
  //DMA通道0
  DMA_IRQ_CLEAN(DMA_CH0);       //清除通道传输中断标志位    (这样才能再次进入中断)
  DMA_EN(DMA_CH0);              //使能通道CHn 硬件请求      (这样才能继续触发DMA传输)
  /*     用户任务       */
  
  EnableInterrupts;
}

/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：FTM0_IRQHandler
*  功能说明：FTM0输入捕捉中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-25
*  备    注：引脚号需要根据自己初始化来修改，参考现有的代码添加自己的功能
*************************************************************************/
void FTM0_IRQHandler()
{
  u8 s = FTM0_STATUS;             //读取捕捉和比较状态  All CHnF bits can be checked using only one read of STATUS.
  u8 n;
  FTM0_STATUS = 0x00;               //清中断标志位

  n = 0;  //通道号
  if( s & (1 << n) )
  {
    FTM_CnSC_REG(FTM0_BASE_PTR, n) &= ~FTM_CnSC_CHIE_MASK; //禁止输入捕捉中断
    /*     用户任务       */
    LED_turn(LED1);    //翻转LED1
    FTM_CnSC_REG(FTM0_BASE_PTR,n) |= FTM_CnSC_CHIE_MASK;  //开启输入捕捉中断

    /*********************/
    //不建议在这里开启输入捕捉中断，而是在main函数里根据需要来开启
    //通道 CH0、CH1、Ch2、Ch3 有滤波器
    //FTM_CnSC_REG(FTM0_BASE_PTR,n) |= FTM_CnSC_CHIE_MASK;  //开启输入捕捉中断
    //delayms(10);        //因为输入的信号跳变过程不稳定，容易触发多次输入捕捉，所以添加延时
    //但考虑到中断不应该过长延时，所以开输入捕捉中断就放在main函数里，根据需要来开启
  }
}


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：PIT0_IRQHandler
*  功能说明：PIT0 定时中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-18    已测试
*  备    注：
*************************************************************************/
void PIT0_IRQHandler(void)
{
  DisableInterrupts;
  
  PIT_Flag_Clear(PIT0);       //清中断标志位
  /*     用户任务       */
  LED_turn(LED1);             //LED1反转
  /*//以下代码是测试LPT脉冲计数器时用的 需要同时打开LPT_Init();
  sprintf(mystr,"CNT :%d",LPTMR0_CNR);
  lptmr_counter_clean(); //清空脉冲计数器计算值
  LCD_clear_line(3);
  LCD_P6x8Str(0,3,mystr,0);  
  */
  
  EnableInterrupts;
}

/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：PIT1_IRQHandler
*  功能说明：PIT1 定时中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-18    已测试
*  备    注：
*************************************************************************/
void PIT1_IRQHandler(void)
{
  DisableInterrupts;
  
  PIT_Flag_Clear(PIT1);       //清中断标志位
  /*     用户任务       */
  //LED_turn(LED2);             //LED2反转
  u8 status;	//用于判断接收/发送状态
  static u8 i=0; //用于屏幕显示行计数
  u8 txbuf[32]={"Hello there, I am NRF24L01\r\n"};	 //发送缓冲
  
  gpio_init(PORTA,19, GPI,LOW);           //初始化IRQ管脚为输入
  NRF_TX_Mode();
  status = NRF_Tx_Dat(txbuf,MAX_ONCE_TX_NUM);
  i++;
  if(i==9)
  {
    i=1;
    OLED_clear_left();
  }
  if(status & TX_DS) //判断发送状态 
  {
    //printf("\r\n 主机端 接收到 从机端 的应答信号，发送成功！ \r\n");	
    OLED_P6x8Str(0,i-1,"Success",0);
  }
  else if(status & MAX_RT)
  {
    //printf("\r\n 主机端 没接收到应答信号，发送次数超过限定值，发送失败。 \r\n");
    OLED_P6x8Str(0,i-1,"FailMax",0);
  }
  else
  {
    //printf("\r\n 未知原因导致发送失败。 \r\n");    
    OLED_P6x8Str(0,i-1,"FailUnknow",0);
  }
  exti_init(PORTA,19, falling_up);        //设置IRQ管脚为 :下降沿触发，内部上拉 用于NRF中断接收  
  
  EnableInterrupts;
}


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：LPT_Handler
*  功能说明：脉冲计数器中断
*  参数说明：无
*  函数返回：无
*  修改时间：2012-2-18    已测试
*  备    注：
*************************************************************************/
void LPT_Handler(void)
{
  LPTMR0_CSR|=LPTMR_CSR_TCF_MASK; //清除 LPTMR 比较标志
  /*     用户任务       */
  //LED_turn(LED0);
}


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：PORTA_IRQHandler
*  功能说明：PORTA端口中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-1-25    已测试
*  备    注：引脚号需要自己初始化来清除
*************************************************************************/
void PORTA_IRQHandler()
{
  u8  n=19;      //引脚号
  
  DisableInterrupts;  
  
  if(PORTA_ISFR & (1<<n))           
  {
    PORTA_ISFR  |= (1<<n);      //写1清中断标志位
    /*     用户任务       */
    //LED_turn(LED2);
    NRF_Handler();
  }
  
  EnableInterrupts;
}

/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：PORTB_IRQHandler
*  功能说明：PORTB端口中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-1-25    已测试
*  备    注：引脚号需要根据自己初始化来修改
*************************************************************************/
void PORTB_IRQHandler()
{
  u8 n;      //引脚号
  
  DisableInterrupts;  
  
  //up
  n=19;
  if(PORTB_ISFR & (1<<n))           
  {
    PORTB_ISFR  |= (1<<n);       //写1清中断标志位
    gpio_turn(PORTA,17);
  }
   
  //down
  n=10;
  if(PORTB_ISFR & (1<<n))           
  {
    PORTB_ISFR  |= (1<<n);       //写1清中断标志位
    
  }
  
  //left
  n=18;
  if(PORTB_ISFR & (1<<n))           
  {
    PORTB_ISFR  |= (1<<n);       //写1清中断标志位
    
  }
  
  //right
  n=9;
  if(PORTB_ISFR & (1<<n))           
  {
    PORTB_ISFR  |= (1<<n);       //写1清中断标志位
    
  }
  
  //ok
  n=20;
  if(PORTB_ISFR & (1<<n))           
  {
    PORTB_ISFR  |= (1<<n);       //写1清中断标志位
    //gpio_turn(PORTA,17);
    Screen_Cut = ~Screen_Cut;
  }
  
  EnableInterrupts;
}


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：PORTE_IRQHandler
*  功能说明：PORTE端口中断服务函数
*  参数说明：无
*  函数返回：无
*  修改时间：2012-1-25    已测试
*  备    注：引脚号需要根据自己初始化来修改
*************************************************************************/
void PORTE_IRQHandler()
{
  u8  n=24;      //引脚号
  
  DisableInterrupts;  
  
  if(PORTE_ISFR & (1<<n))           
  {
    FIFO_Handler();
    PORTE_ISFR  |= (1<<n);       //写1清中断标志位
  }
  
  EnableInterrupts;
}

