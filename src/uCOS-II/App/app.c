#include  <app.h>
#include  "include.h"  		//uC/OS-II系统函数头文件


/*************************************************************************
*                             野火嵌入式开发工作室
*
*  函数名称：Task_Start
*  功能说明：启动任务,初始化滴答时钟
*  参数说明：p_arg       没用
*  函数返回：无
*  修改时间：2012-2-10
*  备    注：
*************************************************************************/
void Task_Start(void *p_arg)
{
  /**************** 初始化 系统滴答时钟 ：用于定时任务调度****************/
  u32  cnts;
  cnts = core_clk_mhz * ( (u32)1000000u / (u32)OS_TICKS_PER_SEC );       /* Determine nbr SysTick increments.                    */
  OS_CPU_SysTickInit(cnts);                                                     /* Init uC/OS periodic time src (SysTick).              */


#if (OS_TASK_STAT_EN > 0)
  /*       开启统计任务           */
  OSStatInit();
#endif


  (void)p_arg;    // 'p_arg' 并没有用到，防止编译器提示警告
  

  /******************* 用户任务区 ************************/
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
  (void)p_arg;    // 'p_arg' 并没有用到，防止编译器提示警告
  
  u32 i = 0;
  
  while(1)
  {
    sprintf(mystr,"count:%d",i++); 
    OLED_P6x8Str(0,2,mystr,0);
    OSTimeDlyHMSM(0, 0, 0, 100);
  }
}
  