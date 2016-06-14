#include  <app.h>
#include  "include.h"  		//uC/OS-IIϵͳ����ͷ�ļ�


/*************************************************************************
*                             Ұ��Ƕ��ʽ����������
*
*  �������ƣ�Task_Start
*  ����˵������������,��ʼ���δ�ʱ��
*  ����˵����p_arg       û��
*  �������أ���
*  �޸�ʱ�䣺2012-2-10
*  ��    ע��
*************************************************************************/
void Task_Start(void *p_arg)
{
  /**************** ��ʼ�� ϵͳ�δ�ʱ�� �����ڶ�ʱ�������****************/
  u32  cnts;
  cnts = core_clk_mhz * ( (u32)1000000u / (u32)OS_TICKS_PER_SEC );       /* Determine nbr SysTick increments.                    */
  OS_CPU_SysTickInit(cnts);                                                     /* Init uC/OS periodic time src (SysTick).              */


#if (OS_TASK_STAT_EN > 0)
  /*       ����ͳ������           */
  OSStatInit();
#endif


  (void)p_arg;    // 'p_arg' ��û���õ�����ֹ��������ʾ����
  

  /******************* �û������� ************************/
  u32 i = 0;
  
  OLED_Init(); 
  OLED_P6x8Str(0,0,"This is a test",0);
  
  while(1)
  {
    sprintf(mystr,"count:%d",i++); 
    OLED_P6x8Str(0,3,mystr,0);
    OSTimeDlyHMSM(0, 0, 0, 10);
  }
}

void OLED_Update(void *p_arg) 
{
  (void)p_arg;    // 'p_arg' ��û���õ�����ֹ��������ʾ����
  
  u32 i = 0;
  
  while(1)
  {
    sprintf(mystr,"count:%d",i++); 
    OLED_P6x8Str(0,2,mystr,0);
    OSTimeDlyHMSM(0, 0, 0, 100);
  }
}
  