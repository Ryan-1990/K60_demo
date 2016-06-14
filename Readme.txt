Author: Nan Li
Build Date: 2013 DEC.
����: ����Ұ����k60����ģ��

�ܽ�˵��: ��Ļ��LED��IO��ʼ������ʵ��Ӳ���ĵ�(�漰��3���ļ�:OLED.c���OLED_Init()����,OLED.h,led.h);A0~3����JTAG,A18���˾���,�û�������

���̽ṹ: �жϺ�����isr.c��  ��ʼ��������Init.c��(�����Լ��Ĺ�����Ҫ�޸ĳ�ʼ������)

һЩ���ù��̵Ĳ��Դ�������
  PS1: ***_init()������Init.c�����
  PS2: ����PIT��ʱ���ж�ֻ���PIT_Init();�����������ѭ�����ż���
  PS3: ����LPT�����ۼ������PIT_Init(),PWM_Init(��C1�Ų���һ��PWM,�����ܳ���ͨ����LPT�Ա���������)��LPT_Init();����ȥ��isr.c��PIT0_IRQHandler()������ע�͵��Ĵ���;�����������ѭ�����ż���;Ӳ���ϰ�C1��C5�̽�
  PS4: ����DMAʱ���DMA_Init(),Ĭ�ϵ�������ͨ��0 PTA19��ʱ��Դ(�����ش���) ����PTD0~PTD7��һ���ֽڵ����ݵ�DMA_BUFF������ ����4�κ󴥷��жϡ���һ�ּ򵥵�Ӳ������˼·: ͨ������PWM_Init()����һ·PWM��PTA19 PTD0~7������һ����3.3V ȫ������һ�������ͣ ͨ��watch���ڿ�DMA_BUFF���������ݶԲ��ԡ�


***********************�ָ���*********************************

/*���Դ��루ʹ��ʱ�Ž�����������ѭ���У�*/

    /****************************************
    * GPIO�����Լ�LED���Դ��� 
    * LED_init();
    * GPIO_Init();
    \***************************************/
    if(PTB0_IN) led(LED0,LED_ON); 
    else led(LED0,LED_OFF);
    
    
    /****************************************
    * PWM���Դ��� 
    * PWM_init();
    \***************************************/
    static u8 i = 0;
    i++;
    if(i>100) i=0;
    FTM_PWM_Duty(FTM0,CH0,i);
    FTM_PWM_freq(FTM0,i*10);
    DLY_ms(50);
    
    
    /****************************************
    * ADC & DAC���Դ��� 
    * DA0��E0�̽�
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
    * EXTI���Դ���  |  FTM���벶׽�жϲ��Դ���
    * A12��A19�̽�  |  A12��C1�̽�
    * LED_init();   |  LED_init();
    * EXTI_Init();  |  FTM_Init();
    \***************************************/
    LED_turn(LED0);
    DLY_ms(500);

***********************�ָ���*********************************
//���´������ڲ���NRF24L01

void main(void)
{
  u8 status;	//�����жϽ���/����״̬
  u8 rxbuf[32];  //���ջ���
  u8 i=0; //������Ļ��ʾ�м���
  
  DisableInterrupts;	 //�����ж�
  PIT_Init();  //PIT��ʱ���жϳ�ʼ��
  OLED_Init();
  NRF_Init();
  EnableInterrupts;	 //�����ж�

  for(;;)
  {
    status = NRF_ISR_Rx_Dat(rxbuf); //�жϽ�������
    if(status==RX_DR) //�жϽ���״̬
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
  
  PIT_Flag_Clear(PIT1);       //���жϱ�־λ
  /*     �û�����       */
  //LED_turn(LED2);             //LED2��ת
  u8 status;	//�����жϽ���/����״̬
  static u8 i=0; //������Ļ��ʾ�м���
  u8 txbuf[32]={"Hello there, I am NRF24L01\r\n"};	 //���ͻ���
  
  gpio_init(PORTA,19, GPI,LOW);           //��ʼ��IRQ�ܽ�Ϊ����
  NRF_TX_Mode();
  status = NRF_Tx_Dat(txbuf,MAX_ONCE_TX_NUM);
  i++;
  if(i==9)
  {
    i=1;
    OLED_clear_left();
  }
  if(status & TX_DS) //�жϷ���״̬ 
  {
    //printf("\r\n ������ ���յ� �ӻ��� ��Ӧ���źţ����ͳɹ��� \r\n");	
    OLED_P6x8Str(0,i-1,"Success",0);
  }
  else if(status & MAX_RT)
  {
    //printf("\r\n ������ û���յ�Ӧ���źţ����ʹ��������޶�ֵ������ʧ�ܡ� \r\n");
    OLED_P6x8Str(0,i-1,"FailMax",0);
  }
  else
  {
    //printf("\r\n δ֪ԭ���·���ʧ�ܡ� \r\n");    
    OLED_P6x8Str(0,i-1,"FailUnknow",0);
  }
  exti_init(PORTA,19, falling_up);        //����IRQ�ܽ�Ϊ :�½��ش������ڲ����� ����NRF�жϽ���
  
  EnableInterrupts;
}

void PORTA_IRQHandler()
{
  u8  n=19;      //���ź�
  
  DisableInterrupts;  
  
  if(PORTA_ISFR & (1<<n))           
  {
    PORTA_ISFR  |= (1<<n);      //д1���жϱ�־λ
    NRF_Handler();
  }
  
  EnableInterrupts;
}

***********************�ָ���*********************************
//���´������ڲ���LCD

void main()
{
  DisableInterrupts;	 //�����ж�
  Init();
  OLED_Init();  
  OLED_P6x8Str(0,0,"This is a test",0);
  //OLED_P6x8Str(0,2,"This is a test",1);
  //SendStr (UART1,"This is a test for K60"); 
  LCD_init();
  EnableInterrupts;	 //�����ж�
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

***********************�ָ���*********************************
//���´������ڲ���OV7725 & LCD

void main()
{
  DisableInterrupts;	 //�����ж�
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
  EnableInterrupts;	 //�����ж�
  
  for(;;)
  {
    if( Ov7725_vsync == 2 )
    {
      Get_Image(); //�ɼ�ͼ������
      if(!Screen_Cut) Show_Image(); //��ͼ����ʾ����Ļ��
      Ov7725_vsync = 0;
    }
  }
}


void PORTE_IRQHandler()
{
  u8  n=24;      //���ź�
  
  DisableInterrupts;  
  
  if(PORTE_ISFR & (1<<n))           
  {
    FIFO_Handler();
    PORTE_ISFR  |= (1<<n);       //д1���жϱ�־λ
  }
  
  EnableInterrupts;
}

***********************�ָ���*********************************
//���´������ڲ���TF�� & FatFs


void main(void)
{
  DisableInterrupts;	 //�����ж�
  Init();
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);
  //SendStr (UART1,"This is a test for K60"); 
  EnableInterrupts;	 //�����ж�
  
  FIL fdst;  //�ļ�
  FATFS fs;  //�ļ�ϵͳ

  u32 size, sizetmp;
  int res;
  char *str = "Hello TF Card~";
  u8 buff[100]=0;

  f_mount(0, &fs); //SD��ϵͳ��ʼ��
  res = f_open(&fdst, "0:/SD_Demo.txt", FA_OPEN_ALWAYS | FA_WRITE | FA_READ);  //���ļ������û�оʹ���������д��
  if( res == FR_DISK_ERR)
  {
    OLED_P6x8Str(0,1,"No SD Card",0);
  }
  else if ( res == FR_OK )
  {
    OLED_P6x8Str(0,1,"Open successfully!",0);
    size = f_size(&fdst);                   //��ȡ�ļ��Ĵ�С
    f_lseek(&fdst, size);                      //��ָ��ָ���ļ�ĩβ
    f_puts(str, &fdst);                     //���ļ���д���ַ���
    OLED_P6x8Str(0,2,"Write done!",0);
    //size = f_size(&fdst);                   //��ȡ�ļ��Ĵ�С
    //f_lseek(&fdst, 0);                      //��ָ��ָ���ļ�����
    //f_read (&fdst, buff, size, (UINT *)&sizetmp);   //��ȡ
    f_close(&fdst);                         //�ر��ļ�
  }
  else
  {
    OLED_P6x8Str(0,1,"Unknown return value",0);
  }

  for(;;);
}

***********************�ָ���*********************************
//���´������ڲ���Flash�Ķ�д(1������2K ��256������ ��������С��λ��һ������)

#define	SECTOR_NUM 200	//������������������ȷ����ȫ

void main()
{
  DisableInterrupts;	 //�����ж�
  Init();
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);
  EnableInterrupts;	 //�����ж�
  
  uint32	data32;
  uint16	data16;
  uint8	data8;
  
  flash_erase_sector(SECTOR_NUM);			//��������
  if( 0==flash_write(SECTOR_NUM,0,0x12345678) )		//д�����ݵ�������ƫ�Ƶ�ַΪ0������һ��д��4�ֽ�
  {
    data32 = flash_read(SECTOR_NUM,0,u32);	//��ȡ4�ֽ�
    sprintf(mystr,"u32 data:0x%08x",data32);
    OLED_P6x8Str(0,1,mystr,0);
    
    data16 = flash_read(SECTOR_NUM,0,u16);	//��ȡ2�ֽ�
    sprintf(mystr,"u16 data:0x%04x",data16);
    OLED_P6x8Str(0,2,mystr,0);
    
    data8 = flash_read(SECTOR_NUM,0,u8);	//��ȡ1�ֽ�
    sprintf(mystr,"u8 data:0x%02x",data8);
    OLED_P6x8Str(0,3,mystr,0);
  }
  
  for(;;);
}

***********************�ָ���*********************************
//���´������ڲ���CMSIS�����DSP���и�����ѧ����

#define DELTA           (0.000001f)             //����������

float32_t a = 0.45454;                          //����������
float32_t cosa, sina, cos2a, sin2a;             //a ������ֵ������ֵ������ֵƽ��������ֵƽ����
float32_t test;                                 //���Խ��

//DSP,����Ҫ���Ԫ��������������ʾ��Ч��������򵥵���һ��Ԫ�������㣬�������
void main(void)
{
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);  
  //float32_t b=1,c=2,d;
  q7_t b = 2, c = 2, d;
  float32_t diff;                             //��ֵ

  //arm_mult_f32(&b,&c,&d,1);
  arm_mult_q7(&b, &c, &d, 1);


  cosa = arm_cos_f32(a);                      //��cosֵ��cosa = cos(a);
  sina = arm_sin_f32(a);                      //��sinֵ��sina = sin(a);

  arm_mult_f32(&cosa, &cosa, &cos2a, 1);      //�˷���cos2a = cosa * cosa ����ƽ��
  arm_mult_f32(&sina, &sina, &sin2a, 1);      //�˷���sin2a = sina * sina ����ƽ��

  arm_add_f32(&cos2a, &sin2a, &test, 1);      //�ӷ���test = cos2a + sin2a = cosa * cosa  + sina * sina = 1

  diff = fabsf( 1.000000000 - test);          //�����ֵ

  if( diff <= DELTA)                          //������Խ���ھ��ȷ�Χ֮��
  {
    OLED_P6x8Str(0,1,"DSP success",0);
    for(;;);
  }
}

***********************�ָ���*********************************
//���´������ڲ���ucos

OS_STK startup_task_stk[TASK_STK_SIZE];		//��������Task_Start��ջ
OS_STK OLED_task_stk[TASK_STK_SIZE];

void main()
{
  OSInit();   //��ʼ��uC/OS
  OSTaskCreate(Task_Start, (void *)0, &startup_task_stk[TASK_STK_SIZE-1], STARTUP_TASK_PRIO);    //����Task_Start����
  OSTaskCreate(OLED_Update, (void *)0, &OLED_task_stk[TASK_STK_SIZE-1], OLED_TASK_PRIO);    //����OLED_Update����
  OSStart();  //�������������
}