Author: Nan Li
Build Date: 2013 DEC.
描述: 基于野火库的k60工程模板

管脚说明: 屏幕和LED的IO初始化根据实际硬件改掉(涉及到3个文件:OLED.c里的OLED_Init()函数,OLED.h,led.h);A0~3接了JTAG,A18接了晶振,用户不能用

工程结构: 中断函数在isr.c里  初始化函数在Init.c里(根据自己的工程需要修改初始化代码)

一些常用工程的测试代码如下
  PS1: ***_init()函数在Init.c的最后
  PS2: 测试PIT定时器中断只需打开PIT_Init();主函数里的死循环空着即可
  PS3: 测试LPT脉冲累加器需打开PIT_Init(),PWM_Init(在C1脚产生一个PWM,在智能车中通常用LPT对编码器计数)和LPT_Init();并且去掉isr.c里PIT0_IRQHandler()函数里注释掉的代码;主函数里的死循环空着即可;硬件上把C1和C5短接
  PS4: 测试DMA时需打开DMA_Init(),默认的配置是通道0 PTA19给时钟源(上升沿触发) 搬运PTD0~PTD7的一个字节的数据到DMA_BUFF数组中 搬运4次后触发中断。给一种简单的硬件调试思路: 通过配置PWM_Init()产生一路PWM给PTA19 PTD0~7的任意一个接3.3V 全速运行一会儿后暂停 通过watch窗口看DMA_BUFF数组中内容对不对。


***********************分割线*********************************

/*测试代码（使用时放进主函数的死循环中）*/

    /****************************************
    * GPIO输入以及LED测试代码 
    * LED_init();
    * GPIO_Init();
    \***************************************/
    if(PTB0_IN) led(LED0,LED_ON); 
    else led(LED0,LED_OFF);
    
    
    /****************************************
    * PWM测试代码 
    * PWM_init();
    \***************************************/
    static u8 i = 0;
    i++;
    if(i>100) i=0;
    FTM_PWM_Duty(FTM0,CH0,i);
    FTM_PWM_freq(FTM0,i*10);
    DLY_ms(50);
    
    
    /****************************************
    * ADC & DAC测试代码 
    * DA0和E0短接
    * ADC_Init();
    * DAC_Init();
    \***************************************/
    static u16 i = 0;
    i++;
    if(i > 4095) i = 0;
    dac_once_convert(DAC0,i);
    sprintf(mystr,"AD :%d",ad_once(ADC1,SE4a,ADC_16bit));
    OLED_clear_line(3);
    OLED_P6x8Str(0,3,mystr,0);
    DLY_ms(10);
    
    
    /****************************************
    * EXTI测试代码  |  FTM输入捕捉中断测试代码
    * A12和A19短接  |  A12和C1短接
    * LED_init();   |  LED_init();
    * EXTI_Init();  |  FTM_Init();
    \***************************************/
    LED_turn(LED0);
    DLY_ms(500);

***********************分割线*********************************
//以下代码用于测试NRF24L01

void main(void)
{
  u8 status;	//用于判断接收/发送状态
  u8 rxbuf[32];  //接收缓冲
  u8 i=0; //用于屏幕显示行计数
  
  DisableInterrupts;	 //关总中断
  PIT_Init();  //PIT定时器中断初始化
  OLED_Init();
  NRF_Init();
  EnableInterrupts;	 //开总中断

  for(;;)
  {
    status = NRF_ISR_Rx_Dat(rxbuf); //中断接收数据
    if(status==RX_DR) //判断接收状态
    {
      i++;
      if(i==9)
      {
        i=1;
        OLED_clear_right();
      }
      OLED_P6x8Str(64,i-1,rxbuf,0);
    }
  } 
}

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

void PORTA_IRQHandler()
{
  u8  n=19;      //引脚号
  
  DisableInterrupts;  
  
  if(PORTA_ISFR & (1<<n))           
  {
    PORTA_ISFR  |= (1<<n);      //写1清中断标志位
    NRF_Handler();
  }
  
  EnableInterrupts;
}

***********************分割线*********************************
//以下代码用于测试LCD

void main()
{
  DisableInterrupts;	 //关总中断
  Init();
  OLED_Init();  
  OLED_P6x8Str(0,0,"This is a test",0);
  //OLED_P6x8Str(0,2,"This is a test",1);
  //SendStr (UART1,"This is a test for K60"); 
  LCD_init();
  EnableInterrupts;	 //开总中断
  Site_t site = {0,0};   
  Size_t size = {128,1};
  
  u8 r=255,g=255,b=255;
  u8 i=0;
  u16 color;
  u8 r_flag=0,g_flag=1,b_flag=1;
  
  for(;;)
  {
    site.y = i;
    color = RGB24_RGB565(r,g,b);
    LCD_rectangle(site, size, color);
    if(r_flag==0)
    {
      r-=2;
      if(r<2) 
      {
        r=255;
        r_flag=1;
        g_flag=0;
      }
    }
    else if(g_flag==0)
    {
      g-=2;
      if(g<2) 
      {
        g=255;
        g_flag=1;
        b_flag=0;
      }
    }
    else if(b_flag==0)
    {
      b-=2;
      if(b<2) 
      {
        b=255;
        b_flag=1;
        r_flag=0;
      }
    }
    i++;
    if(i==127) i=0;
    DLY_ms(5);
  }
}

***********************分割线*********************************
//以下代码用于测试OV7725 & LCD

void main()
{
  DisableInterrupts;	 //关总中断
  Site_t site = {0,0};
  LCD_init();
  Init();
  LCD_P6x8Str(site,"System Init Success!",YELLOW,BLACK);
  DLY_ms(300);
  //OLED_Init(); 
  //OLED_P6x8Str(0,0,"This is a test",0);
  //SendStr (UART1,"This is a test for K60"); 
  if(Ov7725_Init())
  {
    site.y = 8;
    LCD_P6x8Str(site,"OV7725 Init Success!",GBLUE,BLACK);
  }
  DLY_ms(1000);
  EnableInterrupts;	 //开总中断
  
  for(;;)
  {
    if( Ov7725_vsync == 2 )
    {
      Get_Image(); //采集图像数据
      if(!Screen_Cut) Show_Image(); //将图像显示到屏幕上
      Ov7725_vsync = 0;
    }
  }
}


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

***********************分割线*********************************
//以下代码用于测试TF卡 & FatFs


void main(void)
{
  DisableInterrupts;	 //关总中断
  Init();
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);
  //SendStr (UART1,"This is a test for K60"); 
  EnableInterrupts;	 //开总中断
  
  FIL fdst;  //文件
  FATFS fs;  //文件系统

  u32 size, sizetmp;
  int res;
  char *str = "Hello TF Card~";
  u8 buff[100]=0;

  f_mount(0, &fs); //SD卡系统初始化
  res = f_open(&fdst, "0:/SD_Demo.txt", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);  //打开文件，如果没有就创建，带读写打开
  if( res == FR_DISK_ERR)
  {
    OLED_P6x8Str(0,1,"No SD Card",0);
  }
  else if ( res == FR_OK )
  {
    OLED_P6x8Str(0,1,"Open successfully!",0);
    size = f_size(&fdst);                   //获取文件的大小
    f_lseek(&fdst, size);                      //把指针指向文件末尾
    f_puts(str, &fdst);                     //往文件里写入字符串
    OLED_P6x8Str(0,2,"Write done!",0);
    //size = f_size(&fdst);                   //获取文件的大小
    //f_lseek(&fdst, 0);                      //把指针指向文件顶部
    //f_read (&fdst, buff, size, (UINT *)&sizetmp);   //读取
    f_close(&fdst);                         //关闭文件
  }
  else
  {
    OLED_P6x8Str(0,1,"Unknown return value",0);
  }

  for(;;);
}

***********************分割线*********************************
//以下代码用于测试Flash的读写(1个扇区2K 共256个扇区 擦出的最小单位是一个扇区)

#define	SECTOR_NUM 200	//尽量用最后面的扇区，确保安全

void main()
{
  DisableInterrupts;	 //关总中断
  Init();
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);
  EnableInterrupts;	 //开总中断
  
  uint32	data32;
  uint16	data16;
  uint8	data8;
  
  flash_erase_sector(SECTOR_NUM);			//擦除扇区
  if( 0==flash_write(SECTOR_NUM,0,0x12345678) )		//写入数据到扇区，偏移地址为0，必须一次写入4字节
  {
    data32 = flash_read(SECTOR_NUM,0,u32);	//读取4字节
    sprintf(mystr,"u32 data:0x%08x",data32);
    OLED_P6x8Str(0,1,mystr,0);
    
    data16 = flash_read(SECTOR_NUM,0,u16);	//读取2字节
    sprintf(mystr,"u16 data:0x%04x",data16);
    OLED_P6x8Str(0,2,mystr,0);
    
    data8 = flash_read(SECTOR_NUM,0,u8);	//读取1字节
    sprintf(mystr,"u8 data:0x%02x",data8);
    OLED_P6x8Str(0,3,mystr,0);
  }
  
  for(;;);
}

***********************分割线*********************************
//以下代码用于测试CMSIS库操作DSP进行复杂数学运算

#define DELTA           (0.000001f)             //浮点数精度

float32_t a = 0.45454;                          //乱来的数据
float32_t cosa, sina, cos2a, sin2a;             //a 的余弦值、正弦值、余弦值平方、正弦值平方、
float32_t test;                                 //测试结果

//DSP,是需要多个元素来运算来能显示出效果，这里简单得用一个元素来运算，方便理解
void main(void)
{
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);  
  //float32_t b=1,c=2,d;
  q7_t b = 2, c = 2, d;
  float32_t diff;                             //差值

  //arm_mult_f32(&b,&c,&d,1);
  arm_mult_q7(&b, &c, &d, 1);


  cosa = arm_cos_f32(a);                      //求cos值，cosa = cos(a);
  sina = arm_sin_f32(a);                      //求sin值，sina = sin(a);

  arm_mult_f32(&cosa, &cosa, &cos2a, 1);      //乘法，cos2a = cosa * cosa ，即平方
  arm_mult_f32(&sina, &sina, &sin2a, 1);      //乘法，sin2a = sina * sina ，即平方

  arm_add_f32(&cos2a, &sin2a, &test, 1);      //加法，test = cos2a + sin2a = cosa * cosa  + sina * sina = 1

  diff = fabsf( 1.000000000 - test);          //求绝对值

  if( diff <= DELTA)                          //如果测试结果在精度范围之内
  {
    OLED_P6x8Str(0,1,"DSP success",0);
    for(;;);
  }
}

***********************分割线*********************************
//以下代码用于测试ucos

OS_STK startup_task_stk[TASK_STK_SIZE];		//定义任务Task_Start的栈
OS_STK OLED_task_stk[TASK_STK_SIZE];

void main()
{
  OSInit();   //初始化uC/OS
  OSTaskCreate(Task_Start, (void *)0, &startup_task_stk[TASK_STK_SIZE-1], STARTUP_TASK_PRIO);    //创建Task_Start任务
  OSTaskCreate(OLED_Update, (void *)0, &OLED_task_stk[TASK_STK_SIZE-1], OLED_TASK_PRIO);    //创建OLED_Update任务
  OSStart();  //启动多任务管理
}