/******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************
 * 文件名       ：gpio_cfg.h
 * 描述         ：gpio的端口定义头文件
 *
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：野火嵌入式开发工作室
 * 淘宝店       ：http://firestm32.taobao.com
 * 技术支持论坛 ：http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
**********************************************************************************/	
#ifndef __GPIO_CFG_H__
#define __GPIO_CFG_H__

#if 1       //寄存器位操作，有两种方法，前者效率更高，因而此处使用第一种
#define PT(X,n,REG)         BITBAND_REG(PT##X##_BASE_PTR->##REG,n)              //位操作
#else
#define PT(X,n,REG)         (((Dtype *)(&(PT##X##_BASE_PTR->##REG)))->b##n)
#endif

#define PT_BYTE(X,n,REG)    (((Dtype *)(&(PT##X##_BASE_PTR->##REG)))->B[n])
#define PT_WORD(X,n,REG)    (((Dtype *)(&(PT##X##_BASE_PTR->##REG)))->W[n])
#define PT_DWORD(X,REG)     (((Dtype *)(&(PT##X##_BASE_PTR->##REG)))->DW)
/* Sample usage:
PT_BYTE(A,0,PDOR)  =   (((Dtype *)(&(PTA_BASE_PTR->PDOR)))->B[0])

## ，一般用于把两个宏参数贴合在一起，
这里把 PT A  _BASE_PTR-> PDOR ->B[0] 串接起来
*/

//1位操作
#define     _PTXn_T(ptxn,type)   (ptxn##_##type)
#define     PTXn_T(ptxn,type)    _PTXn_T(ptxn,type)

//8位操作
#define     _PTX_Bn_T(ptx,n,type)  (ptx##_B##n##_##type)
#define     PTX_Bn_T(ptx,n,type)   _PTX_Bn_T(ptx,n,type)  

//16位操作
#define     _PTX_Wn_T(ptx,n,type)  (ptx##_W##n##_##type)
#define     PTX_Wn_T(ptx,n,type)   _PTX_Wn_T(ptx,n,type)  

//32位操作
#define     _PTX_T(ptx,type)  (ptx##_##type)
#define     PTX_T(ptx,type)   _PTX_T(ptx,type)

//定义PTA的端口  ——by 野火
#define PTA0_OUT     PTA_BASE_PTR->PDORs.PDOR0
#define PTA1_OUT     PTA_BASE_PTR->PDORs.PDOR1
#define PTA2_OUT     PTA_BASE_PTR->PDORs.PDOR2
#define PTA3_OUT     PTA_BASE_PTR->PDORs.PDOR3
#define PTA4_OUT     PTA_BASE_PTR->PDORs.PDOR4
#define PTA5_OUT     PTA_BASE_PTR->PDORs.PDOR5
#define PTA6_OUT     PTA_BASE_PTR->PDORs.PDOR6
#define PTA7_OUT     PTA_BASE_PTR->PDORs.PDOR7
#define PTA8_OUT     PTA_BASE_PTR->PDORs.PDOR8
#define PTA9_OUT     PTA_BASE_PTR->PDORs.PDOR9
#define PTA10_OUT    PTA_BASE_PTR->PDORs.PDOR10
#define PTA11_OUT    PTA_BASE_PTR->PDORs.PDOR11
#define PTA12_OUT    PTA_BASE_PTR->PDORs.PDOR12
#define PTA13_OUT    PTA_BASE_PTR->PDORs.PDOR13
#define PTA14_OUT    PTA_BASE_PTR->PDORs.PDOR14
#define PTA15_OUT    PTA_BASE_PTR->PDORs.PDOR15
#define PTA16_OUT    PTA_BASE_PTR->PDORs.PDOR16
#define PTA17_OUT    PTA_BASE_PTR->PDORs.PDOR17
#define PTA18_OUT    PTA_BASE_PTR->PDORs.PDOR18
#define PTA19_OUT    PTA_BASE_PTR->PDORs.PDOR19
#define PTA20_OUT    PTA_BASE_PTR->PDORs.PDOR20
#define PTA21_OUT    PTA_BASE_PTR->PDORs.PDOR21
#define PTA22_OUT    PTA_BASE_PTR->PDORs.PDOR22
#define PTA23_OUT    PTA_BASE_PTR->PDORs.PDOR23
#define PTA24_OUT    PTA_BASE_PTR->PDORs.PDOR24
#define PTA25_OUT    PTA_BASE_PTR->PDORs.PDOR25
#define PTA26_OUT    PTA_BASE_PTR->PDORs.PDOR26
#define PTA27_OUT    PTA_BASE_PTR->PDORs.PDOR27
#define PTA28_OUT    PTA_BASE_PTR->PDORs.PDOR28
#define PTA29_OUT    PTA_BASE_PTR->PDORs.PDOR29
#define PTA30_OUT    PTA_BASE_PTR->PDORs.PDOR30
#define PTA31_OUT    PTA_BASE_PTR->PDORs.PDOR31

//定义PTB的端口  ——by 野火
#define PTB0_OUT     PTB_BASE_PTR->PDORs.PDOR0
#define PTB1_OUT     PTB_BASE_PTR->PDORs.PDOR1
#define PTB2_OUT     PTB_BASE_PTR->PDORs.PDOR2
#define PTB3_OUT     PTB_BASE_PTR->PDORs.PDOR3
#define PTB4_OUT     PTB_BASE_PTR->PDORs.PDOR4
#define PTB5_OUT     PTB_BASE_PTR->PDORs.PDOR5
#define PTB6_OUT     PTB_BASE_PTR->PDORs.PDOR6
#define PTB7_OUT     PTB_BASE_PTR->PDORs.PDOR7
#define PTB8_OUT     PTB_BASE_PTR->PDORs.PDOR8
#define PTB9_OUT     PTB_BASE_PTR->PDORs.PDOR9
#define PTB10_OUT    PTB_BASE_PTR->PDORs.PDOR10
#define PTB11_OUT    PTB_BASE_PTR->PDORs.PDOR11
#define PTB12_OUT    PTB_BASE_PTR->PDORs.PDOR12
#define PTB13_OUT    PTB_BASE_PTR->PDORs.PDOR13
#define PTB14_OUT    PTB_BASE_PTR->PDORs.PDOR14
#define PTB15_OUT    PTB_BASE_PTR->PDORs.PDOR15
#define PTB16_OUT    PTB_BASE_PTR->PDORs.PDOR16
#define PTB17_OUT    PTB_BASE_PTR->PDORs.PDOR17
#define PTB18_OUT    PTB_BASE_PTR->PDORs.PDOR18
#define PTB19_OUT    PTB_BASE_PTR->PDORs.PDOR19
#define PTB20_OUT    PTB_BASE_PTR->PDORs.PDOR20
#define PTB21_OUT    PTB_BASE_PTR->PDORs.PDOR21
#define PTB22_OUT    PTB_BASE_PTR->PDORs.PDOR22
#define PTB23_OUT    PTB_BASE_PTR->PDORs.PDOR23
#define PTB24_OUT    PTB_BASE_PTR->PDORs.PDOR24
#define PTB25_OUT    PTB_BASE_PTR->PDORs.PDOR25
#define PTB26_OUT    PTB_BASE_PTR->PDORs.PDOR26
#define PTB27_OUT    PTB_BASE_PTR->PDORs.PDOR27
#define PTB28_OUT    PTB_BASE_PTR->PDORs.PDOR28
#define PTB29_OUT    PTB_BASE_PTR->PDORs.PDOR29
#define PTB30_OUT    PTB_BASE_PTR->PDORs.PDOR30
#define PTB31_OUT    PTB_BASE_PTR->PDORs.PDOR31

//定义PTC的端口  ——by 野火
#define PTC0_OUT     PTC_BASE_PTR->PDORs.PDOR0
#define PTC1_OUT     PTC_BASE_PTR->PDORs.PDOR1
#define PTC2_OUT     PTC_BASE_PTR->PDORs.PDOR2
#define PTC3_OUT     PTC_BASE_PTR->PDORs.PDOR3
#define PTC4_OUT     PTC_BASE_PTR->PDORs.PDOR4
#define PTC5_OUT     PTC_BASE_PTR->PDORs.PDOR5
#define PTC6_OUT     PTC_BASE_PTR->PDORs.PDOR6
#define PTC7_OUT     PTC_BASE_PTR->PDORs.PDOR7
#define PTC8_OUT     PTC_BASE_PTR->PDORs.PDOR8
#define PTC9_OUT     PTC_BASE_PTR->PDORs.PDOR9
#define PTC10_OUT    PTC_BASE_PTR->PDORs.PDOR10
#define PTC11_OUT    PTC_BASE_PTR->PDORs.PDOR11
#define PTC12_OUT    PTC_BASE_PTR->PDORs.PDOR12
#define PTC13_OUT    PTC_BASE_PTR->PDORs.PDOR13
#define PTC14_OUT    PTC_BASE_PTR->PDORs.PDOR14
#define PTC15_OUT    PTC_BASE_PTR->PDORs.PDOR15
#define PTC16_OUT    PTC_BASE_PTR->PDORs.PDOR16
#define PTC17_OUT    PTC_BASE_PTR->PDORs.PDOR17
#define PTC18_OUT    PTC_BASE_PTR->PDORs.PDOR18
#define PTC19_OUT    PTC_BASE_PTR->PDORs.PDOR19
#define PTC20_OUT    PTC_BASE_PTR->PDORs.PDOR20
#define PTC21_OUT    PTC_BASE_PTR->PDORs.PDOR21
#define PTC22_OUT    PTC_BASE_PTR->PDORs.PDOR22
#define PTC23_OUT    PTC_BASE_PTR->PDORs.PDOR23
#define PTC24_OUT    PTC_BASE_PTR->PDORs.PDOR24
#define PTC25_OUT    PTC_BASE_PTR->PDORs.PDOR25
#define PTC26_OUT    PTC_BASE_PTR->PDORs.PDOR26
#define PTC27_OUT    PTC_BASE_PTR->PDORs.PDOR27
#define PTC28_OUT    PTC_BASE_PTR->PDORs.PDOR28
#define PTC29_OUT    PTC_BASE_PTR->PDORs.PDOR29
#define PTC30_OUT    PTC_BASE_PTR->PDORs.PDOR30
#define PTC31_OUT    PTC_BASE_PTR->PDORs.PDOR31

//定义PTD的端口  ——by 野火
#define PTD0_OUT     PTD_BASE_PTR->PDORs.PDOR0
#define PTD1_OUT     PTD_BASE_PTR->PDORs.PDOR1
#define PTD2_OUT     PTD_BASE_PTR->PDORs.PDOR2
#define PTD3_OUT     PTD_BASE_PTR->PDORs.PDOR3
#define PTD4_OUT     PTD_BASE_PTR->PDORs.PDOR4
#define PTD5_OUT     PTD_BASE_PTR->PDORs.PDOR5
#define PTD6_OUT     PTD_BASE_PTR->PDORs.PDOR6
#define PTD7_OUT     PTD_BASE_PTR->PDORs.PDOR7
#define PTD8_OUT     PTD_BASE_PTR->PDORs.PDOR8
#define PTD9_OUT     PTD_BASE_PTR->PDORs.PDOR9
#define PTD10_OUT    PTD_BASE_PTR->PDORs.PDOR10
#define PTD11_OUT    PTD_BASE_PTR->PDORs.PDOR11
#define PTD12_OUT    PTD_BASE_PTR->PDORs.PDOR12
#define PTD13_OUT    PTD_BASE_PTR->PDORs.PDOR13
#define PTD14_OUT    PTD_BASE_PTR->PDORs.PDOR14
#define PTD15_OUT    PTD_BASE_PTR->PDORs.PDOR15
#define PTD16_OUT    PTD_BASE_PTR->PDORs.PDOR16
#define PTD17_OUT    PTD_BASE_PTR->PDORs.PDOR17
#define PTD18_OUT    PTD_BASE_PTR->PDORs.PDOR18
#define PTD19_OUT    PTD_BASE_PTR->PDORs.PDOR19
#define PTD20_OUT    PTD_BASE_PTR->PDORs.PDOR20
#define PTD21_OUT    PTD_BASE_PTR->PDORs.PDOR21
#define PTD22_OUT    PTD_BASE_PTR->PDORs.PDOR22
#define PTD23_OUT    PTD_BASE_PTR->PDORs.PDOR23
#define PTD24_OUT    PTD_BASE_PTR->PDORs.PDOR24
#define PTD25_OUT    PTD_BASE_PTR->PDORs.PDOR25
#define PTD26_OUT    PTD_BASE_PTR->PDORs.PDOR26
#define PTD27_OUT    PTD_BASE_PTR->PDORs.PDOR27
#define PTD28_OUT    PTD_BASE_PTR->PDORs.PDOR28
#define PTD29_OUT    PTD_BASE_PTR->PDORs.PDOR29
#define PTD30_OUT    PTD_BASE_PTR->PDORs.PDOR30
#define PTD31_OUT    PTD_BASE_PTR->PDORs.PDOR31

//定义PTE的端口  ——by 野火
#define PTE0_OUT     PTE_BASE_PTR->PDORs.PDOR0
#define PTE1_OUT     PTE_BASE_PTR->PDORs.PDOR1
#define PTE2_OUT     PTE_BASE_PTR->PDORs.PDOR2
#define PTE3_OUT     PTE_BASE_PTR->PDORs.PDOR3
#define PTE4_OUT     PTE_BASE_PTR->PDORs.PDOR4
#define PTE5_OUT     PTE_BASE_PTR->PDORs.PDOR5
#define PTE6_OUT     PTE_BASE_PTR->PDORs.PDOR6
#define PTE7_OUT     PTE_BASE_PTR->PDORs.PDOR7
#define PTE8_OUT     PTE_BASE_PTR->PDORs.PDOR8
#define PTE9_OUT     PTE_BASE_PTR->PDORs.PDOR9
#define PTE10_OUT    PTE_BASE_PTR->PDORs.PDOR10
#define PTE11_OUT    PTE_BASE_PTR->PDORs.PDOR11
#define PTE12_OUT    PTE_BASE_PTR->PDORs.PDOR12
#define PTE13_OUT    PTE_BASE_PTR->PDORs.PDOR13
#define PTE14_OUT    PTE_BASE_PTR->PDORs.PDOR14
#define PTE15_OUT    PTE_BASE_PTR->PDORs.PDOR15
#define PTE16_OUT    PTE_BASE_PTR->PDORs.PDOR16
#define PTE17_OUT    PTE_BASE_PTR->PDORs.PDOR17
#define PTE18_OUT    PTE_BASE_PTR->PDORs.PDOR18
#define PTE19_OUT    PTE_BASE_PTR->PDORs.PDOR19
#define PTE20_OUT    PTE_BASE_PTR->PDORs.PDOR20
#define PTE21_OUT    PTE_BASE_PTR->PDORs.PDOR21
#define PTE22_OUT    PTE_BASE_PTR->PDORs.PDOR22
#define PTE23_OUT    PTE_BASE_PTR->PDORs.PDOR23
#define PTE24_OUT    PTE_BASE_PTR->PDORs.PDOR24
#define PTE25_OUT    PTE_BASE_PTR->PDORs.PDOR25
#define PTE26_OUT    PTE_BASE_PTR->PDORs.PDOR26
#define PTE27_OUT    PTE_BASE_PTR->PDORs.PDOR27
#define PTE28_OUT    PTE_BASE_PTR->PDORs.PDOR28
#define PTE29_OUT    PTE_BASE_PTR->PDORs.PDOR29
#define PTE30_OUT    PTE_BASE_PTR->PDORs.PDOR30
#define PTE31_OUT    PTE_BASE_PTR->PDORs.PDOR31



//定义PTA的输出输入方向  ——by 野火
#define DDRA0       PTA_BASE_PTR->DDRs.DDR0
#define DDRA1       PTA_BASE_PTR->DDRs.DDR1
#define DDRA2       PTA_BASE_PTR->DDRs.DDR2
#define DDRA3       PTA_BASE_PTR->DDRs.DDR3
#define DDRA4       PTA_BASE_PTR->DDRs.DDR4
#define DDRA5       PTA_BASE_PTR->DDRs.DDR5
#define DDRA6       PTA_BASE_PTR->DDRs.DDR6
#define DDRA7       PTA_BASE_PTR->DDRs.DDR7
#define DDRA8       PTA_BASE_PTR->DDRs.DDR8
#define DDRA9       PTA_BASE_PTR->DDRs.DDR9
#define DDRA10      PTA_BASE_PTR->DDRs.DDR10
#define DDRA11      PTA_BASE_PTR->DDRs.DDR11
#define DDRA12      PTA_BASE_PTR->DDRs.DDR12
#define DDRA13      PTA_BASE_PTR->DDRs.DDR13
#define DDRA14      PTA_BASE_PTR->DDRs.DDR14
#define DDRA15      PTA_BASE_PTR->DDRs.DDR15
#define DDRA16      PTA_BASE_PTR->DDRs.DDR16
#define DDRA17      PTA_BASE_PTR->DDRs.DDR17
#define DDRA18      PTA_BASE_PTR->DDRs.DDR18
#define DDRA19      PTA_BASE_PTR->DDRs.DDR19
#define DDRA20      PTA_BASE_PTR->DDRs.DDR20
#define DDRA21      PTA_BASE_PTR->DDRs.DDR21
#define DDRA22      PTA_BASE_PTR->DDRs.DDR22
#define DDRA23      PTA_BASE_PTR->DDRs.DDR23
#define DDRA24      PTA_BASE_PTR->DDRs.DDR24
#define DDRA25      PTA_BASE_PTR->DDRs.DDR25
#define DDRA26      PTA_BASE_PTR->DDRs.DDR26
#define DDRA27      PTA_BASE_PTR->DDRs.DDR27
#define DDRA28      PTA_BASE_PTR->DDRs.DDR28
#define DDRA29      PTA_BASE_PTR->DDRs.DDR29
#define DDRA30      PTA_BASE_PTR->DDRs.DDR30
#define DDRA31      PTA_BASE_PTR->DDRs.DDR31

//定义PTB的输出输入方向  ——by 野火
#define DDRB0       PTB_BASE_PTR->DDRs.DDR0
#define DDRB1       PTB_BASE_PTR->DDRs.DDR1
#define DDRB2       PTB_BASE_PTR->DDRs.DDR2
#define DDRB3       PTB_BASE_PTR->DDRs.DDR3
#define DDRB4       PTB_BASE_PTR->DDRs.DDR4
#define DDRB5       PTB_BASE_PTR->DDRs.DDR5
#define DDRB6       PTB_BASE_PTR->DDRs.DDR6
#define DDRB7       PTB_BASE_PTR->DDRs.DDR7
#define DDRB8       PTB_BASE_PTR->DDRs.DDR8
#define DDRB9       PTB_BASE_PTR->DDRs.DDR9
#define DDRB10      PTB_BASE_PTR->DDRs.DDR10
#define DDRB11      PTB_BASE_PTR->DDRs.DDR11
#define DDRB12      PTB_BASE_PTR->DDRs.DDR12
#define DDRB13      PTB_BASE_PTR->DDRs.DDR13
#define DDRB14      PTB_BASE_PTR->DDRs.DDR14
#define DDRB15      PTB_BASE_PTR->DDRs.DDR15
#define DDRB16      PTB_BASE_PTR->DDRs.DDR16
#define DDRB17      PTB_BASE_PTR->DDRs.DDR17
#define DDRB18      PTB_BASE_PTR->DDRs.DDR18
#define DDRB19      PTB_BASE_PTR->DDRs.DDR19
#define DDRB20      PTB_BASE_PTR->DDRs.DDR20
#define DDRB21      PTB_BASE_PTR->DDRs.DDR21
#define DDRB22      PTB_BASE_PTR->DDRs.DDR22
#define DDRB23      PTB_BASE_PTR->DDRs.DDR23
#define DDRB24      PTB_BASE_PTR->DDRs.DDR24
#define DDRB25      PTB_BASE_PTR->DDRs.DDR25
#define DDRB26      PTB_BASE_PTR->DDRs.DDR26
#define DDRB27      PTB_BASE_PTR->DDRs.DDR27
#define DDRB28      PTB_BASE_PTR->DDRs.DDR28
#define DDRB29      PTB_BASE_PTR->DDRs.DDR29
#define DDRB30      PTB_BASE_PTR->DDRs.DDR30
#define DDRB31      PTB_BASE_PTR->DDRs.DDR31

//定义PTC的输出输入方向  ——by 野火
#define DDRC0       PTC_BASE_PTR->DDRs.DDR0
#define DDRC1       PTC_BASE_PTR->DDRs.DDR1
#define DDRC2       PTC_BASE_PTR->DDRs.DDR2
#define DDRC3       PTC_BASE_PTR->DDRs.DDR3
#define DDRC4       PTC_BASE_PTR->DDRs.DDR4
#define DDRC5       PTC_BASE_PTR->DDRs.DDR5
#define DDRC6       PTC_BASE_PTR->DDRs.DDR6
#define DDRC7       PTC_BASE_PTR->DDRs.DDR7
#define DDRC8       PTC_BASE_PTR->DDRs.DDR8
#define DDRC9       PTC_BASE_PTR->DDRs.DDR9
#define DDRC10      PTC_BASE_PTR->DDRs.DDR10
#define DDRC11      PTC_BASE_PTR->DDRs.DDR11
#define DDRC12      PTC_BASE_PTR->DDRs.DDR12
#define DDRC13      PTC_BASE_PTR->DDRs.DDR13
#define DDRC14      PTC_BASE_PTR->DDRs.DDR14
#define DDRC15      PTC_BASE_PTR->DDRs.DDR15
#define DDRC16      PTC_BASE_PTR->DDRs.DDR16
#define DDRC17      PTC_BASE_PTR->DDRs.DDR17
#define DDRC18      PTC_BASE_PTR->DDRs.DDR18
#define DDRC19      PTC_BASE_PTR->DDRs.DDR19
#define DDRC20      PTC_BASE_PTR->DDRs.DDR20
#define DDRC21      PTC_BASE_PTR->DDRs.DDR21
#define DDRC22      PTC_BASE_PTR->DDRs.DDR22
#define DDRC23      PTC_BASE_PTR->DDRs.DDR23
#define DDRC24      PTC_BASE_PTR->DDRs.DDR24
#define DDRC25      PTC_BASE_PTR->DDRs.DDR25
#define DDRC26      PTC_BASE_PTR->DDRs.DDR26
#define DDRC27      PTC_BASE_PTR->DDRs.DDR27
#define DDRC28      PTC_BASE_PTR->DDRs.DDR28
#define DDRC29      PTC_BASE_PTR->DDRs.DDR29
#define DDRC30      PTC_BASE_PTR->DDRs.DDR30
#define DDRC31      PTC_BASE_PTR->DDRs.DDR31

//定义PTD的输出输入方向  ——by 野火
#define DDRD0       PTD_BASE_PTR->DDRs.DDR0
#define DDRD1       PTD_BASE_PTR->DDRs.DDR1
#define DDRD2       PTD_BASE_PTR->DDRs.DDR2
#define DDRD3       PTD_BASE_PTR->DDRs.DDR3
#define DDRD4       PTD_BASE_PTR->DDRs.DDR4
#define DDRD5       PTD_BASE_PTR->DDRs.DDR5
#define DDRD6       PTD_BASE_PTR->DDRs.DDR6
#define DDRD7       PTD_BASE_PTR->DDRs.DDR7
#define DDRD8       PTD_BASE_PTR->DDRs.DDR8
#define DDRD9       PTD_BASE_PTR->DDRs.DDR9
#define DDRD10      PTD_BASE_PTR->DDRs.DDR10
#define DDRD11      PTD_BASE_PTR->DDRs.DDR11
#define DDRD12      PTD_BASE_PTR->DDRs.DDR12
#define DDRD13      PTD_BASE_PTR->DDRs.DDR13
#define DDRD14      PTD_BASE_PTR->DDRs.DDR14
#define DDRD15      PTD_BASE_PTR->DDRs.DDR15
#define DDRD16      PTD_BASE_PTR->DDRs.DDR16
#define DDRD17      PTD_BASE_PTR->DDRs.DDR17
#define DDRD18      PTD_BASE_PTR->DDRs.DDR18
#define DDRD19      PTD_BASE_PTR->DDRs.DDR19
#define DDRD20      PTD_BASE_PTR->DDRs.DDR20
#define DDRD21      PTD_BASE_PTR->DDRs.DDR21
#define DDRD22      PTD_BASE_PTR->DDRs.DDR22
#define DDRD23      PTD_BASE_PTR->DDRs.DDR23
#define DDRD24      PTD_BASE_PTR->DDRs.DDR24
#define DDRD25      PTD_BASE_PTR->DDRs.DDR25
#define DDRD26      PTD_BASE_PTR->DDRs.DDR26
#define DDRD27      PTD_BASE_PTR->DDRs.DDR27
#define DDRD28      PTD_BASE_PTR->DDRs.DDR28
#define DDRD29      PTD_BASE_PTR->DDRs.DDR29
#define DDRD30      PTD_BASE_PTR->DDRs.DDR30
#define DDRD31      PTD_BASE_PTR->DDRs.DDR31

//定义PTE的输出输入方向  ——by 野火
#define DDRE0       PTE_BASE_PTR->DDRs.DDR0
#define DDRE1       PTE_BASE_PTR->DDRs.DDR1
#define DDRE2       PTE_BASE_PTR->DDRs.DDR2
#define DDRE3       PTE_BASE_PTR->DDRs.DDR3
#define DDRE4       PTE_BASE_PTR->DDRs.DDR4
#define DDRE5       PTE_BASE_PTR->DDRs.DDR5
#define DDRE6       PTE_BASE_PTR->DDRs.DDR6
#define DDRE7       PTE_BASE_PTR->DDRs.DDR7
#define DDRE8       PTE_BASE_PTR->DDRs.DDR8
#define DDRE9       PTE_BASE_PTR->DDRs.DDR9
#define DDRE10      PTE_BASE_PTR->DDRs.DDR10
#define DDRE11      PTE_BASE_PTR->DDRs.DDR11
#define DDRE12      PTE_BASE_PTR->DDRs.DDR12
#define DDRE13      PTE_BASE_PTR->DDRs.DDR13
#define DDRE14      PTE_BASE_PTR->DDRs.DDR14
#define DDRE15      PTE_BASE_PTR->DDRs.DDR15
#define DDRE16      PTE_BASE_PTR->DDRs.DDR16
#define DDRE17      PTE_BASE_PTR->DDRs.DDR17
#define DDRE18      PTE_BASE_PTR->DDRs.DDR18
#define DDRE19      PTE_BASE_PTR->DDRs.DDR19
#define DDRE20      PTE_BASE_PTR->DDRs.DDR20
#define DDRE21      PTE_BASE_PTR->DDRs.DDR21
#define DDRE22      PTE_BASE_PTR->DDRs.DDR22
#define DDRE23      PTE_BASE_PTR->DDRs.DDR23
#define DDRE24      PTE_BASE_PTR->DDRs.DDR24
#define DDRE25      PTE_BASE_PTR->DDRs.DDR25
#define DDRE26      PTE_BASE_PTR->DDRs.DDR26
#define DDRE27      PTE_BASE_PTR->DDRs.DDR27
#define DDRE28      PTE_BASE_PTR->DDRs.DDR28
#define DDRE29      PTE_BASE_PTR->DDRs.DDR29
#define DDRE30      PTE_BASE_PTR->DDRs.DDR30
#define DDRE31      PTE_BASE_PTR->DDRs.DDR31


//定义PTA的输入端口  ——by 野火
#define PTA0_IN     PTA_BASE_PTR->PDIRs.PDIR0
#define PTA1_IN     PTA_BASE_PTR->PDIRs.PDIR1
#define PTA2_IN     PTA_BASE_PTR->PDIRs.PDIR2
#define PTA3_IN     PTA_BASE_PTR->PDIRs.PDIR3
#define PTA4_IN     PTA_BASE_PTR->PDIRs.PDIR4
#define PTA5_IN     PTA_BASE_PTR->PDIRs.PDIR5
#define PTA6_IN     PTA_BASE_PTR->PDIRs.PDIR6
#define PTA7_IN     PTA_BASE_PTR->PDIRs.PDIR7
#define PTA8_IN     PTA_BASE_PTR->PDIRs.PDIR8
#define PTA9_IN     PTA_BASE_PTR->PDIRs.PDIR9
#define PTA10_IN    PTA_BASE_PTR->PDIRs.PDIR10
#define PTA11_IN    PTA_BASE_PTR->PDIRs.PDIR11
#define PTA12_IN    PTA_BASE_PTR->PDIRs.PDIR12
#define PTA13_IN    PTA_BASE_PTR->PDIRs.PDIR13
#define PTA14_IN    PTA_BASE_PTR->PDIRs.PDIR14
#define PTA15_IN    PTA_BASE_PTR->PDIRs.PDIR15
#define PTA16_IN    PTA_BASE_PTR->PDIRs.PDIR16
#define PTA17_IN    PTA_BASE_PTR->PDIRs.PDIR17
#define PTA18_IN    PTA_BASE_PTR->PDIRs.PDIR18
#define PTA19_IN    PTA_BASE_PTR->PDIRs.PDIR19
#define PTA20_IN    PTA_BASE_PTR->PDIRs.PDIR20
#define PTA21_IN    PTA_BASE_PTR->PDIRs.PDIR21
#define PTA22_IN    PTA_BASE_PTR->PDIRs.PDIR22
#define PTA23_IN    PTA_BASE_PTR->PDIRs.PDIR23
#define PTA24_IN    PTA_BASE_PTR->PDIRs.PDIR24
#define PTA25_IN    PTA_BASE_PTR->PDIRs.PDIR25
#define PTA26_IN    PTA_BASE_PTR->PDIRs.PDIR26
#define PTA27_IN    PTA_BASE_PTR->PDIRs.PDIR27
#define PTA28_IN    PTA_BASE_PTR->PDIRs.PDIR28
#define PTA29_IN    PTA_BASE_PTR->PDIRs.PDIR29
#define PTA30_IN    PTA_BASE_PTR->PDIRs.PDIR30
#define PTA31_IN    PTA_BASE_PTR->PDIRs.PDIR31

//定义PTB的输入端口  ——by 野火
#define PTB0_IN     PTB_BASE_PTR->PDIRs.PDIR0
#define PTB1_IN     PTB_BASE_PTR->PDIRs.PDIR1
#define PTB2_IN     PTB_BASE_PTR->PDIRs.PDIR2
#define PTB3_IN     PTB_BASE_PTR->PDIRs.PDIR3
#define PTB4_IN     PTB_BASE_PTR->PDIRs.PDIR4
#define PTB5_IN     PTB_BASE_PTR->PDIRs.PDIR5
#define PTB6_IN     PTB_BASE_PTR->PDIRs.PDIR6
#define PTB7_IN     PTB_BASE_PTR->PDIRs.PDIR7
#define PTB8_IN     PTB_BASE_PTR->PDIRs.PDIR8
#define PTB9_IN     PTB_BASE_PTR->PDIRs.PDIR9
#define PTB10_IN    PTB_BASE_PTR->PDIRs.PDIR10
#define PTB11_IN    PTB_BASE_PTR->PDIRs.PDIR11
#define PTB12_IN    PTB_BASE_PTR->PDIRs.PDIR12
#define PTB13_IN    PTB_BASE_PTR->PDIRs.PDIR13
#define PTB14_IN    PTB_BASE_PTR->PDIRs.PDIR14
#define PTB15_IN    PTB_BASE_PTR->PDIRs.PDIR15
#define PTB16_IN    PTB_BASE_PTR->PDIRs.PDIR16
#define PTB17_IN    PTB_BASE_PTR->PDIRs.PDIR17
#define PTB18_IN    PTB_BASE_PTR->PDIRs.PDIR18
#define PTB19_IN    PTB_BASE_PTR->PDIRs.PDIR19
#define PTB20_IN    PTB_BASE_PTR->PDIRs.PDIR20
#define PTB21_IN    PTB_BASE_PTR->PDIRs.PDIR21
#define PTB22_IN    PTB_BASE_PTR->PDIRs.PDIR22
#define PTB23_IN    PTB_BASE_PTR->PDIRs.PDIR23
#define PTB24_IN    PTB_BASE_PTR->PDIRs.PDIR24
#define PTB25_IN    PTB_BASE_PTR->PDIRs.PDIR25
#define PTB26_IN    PTB_BASE_PTR->PDIRs.PDIR26
#define PTB27_IN    PTB_BASE_PTR->PDIRs.PDIR27
#define PTB28_IN    PTB_BASE_PTR->PDIRs.PDIR28
#define PTB29_IN    PTB_BASE_PTR->PDIRs.PDIR29
#define PTB30_IN    PTB_BASE_PTR->PDIRs.PDIR30
#define PTB31_IN    PTB_BASE_PTR->PDIRs.PDIR31

//定义PTC的输入端口  ——by 野火
#define PTC0_IN     PTC_BASE_PTR->PDIRs.PDIR0
#define PTC1_IN     PTC_BASE_PTR->PDIRs.PDIR1
#define PTC2_IN     PTC_BASE_PTR->PDIRs.PDIR2
#define PTC3_IN     PTC_BASE_PTR->PDIRs.PDIR3
#define PTC4_IN     PTC_BASE_PTR->PDIRs.PDIR4
#define PTC5_IN     PTC_BASE_PTR->PDIRs.PDIR5
#define PTC6_IN     PTC_BASE_PTR->PDIRs.PDIR6
#define PTC7_IN     PTC_BASE_PTR->PDIRs.PDIR7
#define PTC8_IN     PTC_BASE_PTR->PDIRs.PDIR8
#define PTC9_IN     PTC_BASE_PTR->PDIRs.PDIR9
#define PTC10_IN    PTC_BASE_PTR->PDIRs.PDIR10
#define PTC11_IN    PTC_BASE_PTR->PDIRs.PDIR11
#define PTC12_IN    PTC_BASE_PTR->PDIRs.PDIR12
#define PTC13_IN    PTC_BASE_PTR->PDIRs.PDIR13
#define PTC14_IN    PTC_BASE_PTR->PDIRs.PDIR14
#define PTC15_IN    PTC_BASE_PTR->PDIRs.PDIR15
#define PTC16_IN    PTC_BASE_PTR->PDIRs.PDIR16
#define PTC17_IN    PTC_BASE_PTR->PDIRs.PDIR17
#define PTC18_IN    PTC_BASE_PTR->PDIRs.PDIR18
#define PTC19_IN    PTC_BASE_PTR->PDIRs.PDIR19
#define PTC20_IN    PTC_BASE_PTR->PDIRs.PDIR20
#define PTC21_IN    PTC_BASE_PTR->PDIRs.PDIR21
#define PTC22_IN    PTC_BASE_PTR->PDIRs.PDIR22
#define PTC23_IN    PTC_BASE_PTR->PDIRs.PDIR23
#define PTC24_IN    PTC_BASE_PTR->PDIRs.PDIR24
#define PTC25_IN    PTC_BASE_PTR->PDIRs.PDIR25
#define PTC26_IN    PTC_BASE_PTR->PDIRs.PDIR26
#define PTC27_IN    PTC_BASE_PTR->PDIRs.PDIR27
#define PTC28_IN    PTC_BASE_PTR->PDIRs.PDIR28
#define PTC29_IN    PTC_BASE_PTR->PDIRs.PDIR29
#define PTC30_IN    PTC_BASE_PTR->PDIRs.PDIR30
#define PTC31_IN    PTC_BASE_PTR->PDIRs.PDIR31

//定义PTD的输入端口  ——by 野火
#define PTD0_IN     PTD_BASE_PTR->PDIRs.PDIR0
#define PTD1_IN     PTD_BASE_PTR->PDIRs.PDIR1
#define PTD2_IN     PTD_BASE_PTR->PDIRs.PDIR2
#define PTD3_IN     PTD_BASE_PTR->PDIRs.PDIR3
#define PTD4_IN     PTD_BASE_PTR->PDIRs.PDIR4
#define PTD5_IN     PTD_BASE_PTR->PDIRs.PDIR5
#define PTD6_IN     PTD_BASE_PTR->PDIRs.PDIR6
#define PTD7_IN     PTD_BASE_PTR->PDIRs.PDIR7
#define PTD8_IN     PTD_BASE_PTR->PDIRs.PDIR8
#define PTD9_IN     PTD_BASE_PTR->PDIRs.PDIR9
#define PTD10_IN    PTD_BASE_PTR->PDIRs.PDIR10
#define PTD11_IN    PTD_BASE_PTR->PDIRs.PDIR11
#define PTD12_IN    PTD_BASE_PTR->PDIRs.PDIR12
#define PTD13_IN    PTD_BASE_PTR->PDIRs.PDIR13
#define PTD14_IN    PTD_BASE_PTR->PDIRs.PDIR14
#define PTD15_IN    PTD_BASE_PTR->PDIRs.PDIR15
#define PTD16_IN    PTD_BASE_PTR->PDIRs.PDIR16
#define PTD17_IN    PTD_BASE_PTR->PDIRs.PDIR17
#define PTD18_IN    PTD_BASE_PTR->PDIRs.PDIR18
#define PTD19_IN    PTD_BASE_PTR->PDIRs.PDIR19
#define PTD20_IN    PTD_BASE_PTR->PDIRs.PDIR20
#define PTD21_IN    PTD_BASE_PTR->PDIRs.PDIR21
#define PTD22_IN    PTD_BASE_PTR->PDIRs.PDIR22
#define PTD23_IN    PTD_BASE_PTR->PDIRs.PDIR23
#define PTD24_IN    PTD_BASE_PTR->PDIRs.PDIR24
#define PTD25_IN    PTD_BASE_PTR->PDIRs.PDIR25
#define PTD26_IN    PTD_BASE_PTR->PDIRs.PDIR26
#define PTD27_IN    PTD_BASE_PTR->PDIRs.PDIR27
#define PTD28_IN    PTD_BASE_PTR->PDIRs.PDIR28
#define PTD29_IN    PTD_BASE_PTR->PDIRs.PDIR29
#define PTD30_IN    PTD_BASE_PTR->PDIRs.PDIR30
#define PTD31_IN    PTD_BASE_PTR->PDIRs.PDIR31

//定义PTE的输入端口  ——by 野火
#define PTE0_IN     PTE_BASE_PTR->PDIRs.PDIR0
#define PTE1_IN     PTE_BASE_PTR->PDIRs.PDIR1
#define PTE2_IN     PTE_BASE_PTR->PDIRs.PDIR2
#define PTE3_IN     PTE_BASE_PTR->PDIRs.PDIR3
#define PTE4_IN     PTE_BASE_PTR->PDIRs.PDIR4
#define PTE5_IN     PTE_BASE_PTR->PDIRs.PDIR5
#define PTE6_IN     PTE_BASE_PTR->PDIRs.PDIR6
#define PTE7_IN     PTE_BASE_PTR->PDIRs.PDIR7
#define PTE8_IN     PTE_BASE_PTR->PDIRs.PDIR8
#define PTE9_IN     PTE_BASE_PTR->PDIRs.PDIR9
#define PTE10_IN    PTE_BASE_PTR->PDIRs.PDIR10
#define PTE11_IN    PTE_BASE_PTR->PDIRs.PDIR11
#define PTE12_IN    PTE_BASE_PTR->PDIRs.PDIR12
#define PTE13_IN    PTE_BASE_PTR->PDIRs.PDIR13
#define PTE14_IN    PTE_BASE_PTR->PDIRs.PDIR14
#define PTE15_IN    PTE_BASE_PTR->PDIRs.PDIR15
#define PTE16_IN    PTE_BASE_PTR->PDIRs.PDIR16
#define PTE17_IN    PTE_BASE_PTR->PDIRs.PDIR17
#define PTE18_IN    PTE_BASE_PTR->PDIRs.PDIR18
#define PTE19_IN    PTE_BASE_PTR->PDIRs.PDIR19
#define PTE20_IN    PTE_BASE_PTR->PDIRs.PDIR20
#define PTE21_IN    PTE_BASE_PTR->PDIRs.PDIR21
#define PTE22_IN    PTE_BASE_PTR->PDIRs.PDIR22
#define PTE23_IN    PTE_BASE_PTR->PDIRs.PDIR23
#define PTE24_IN    PTE_BASE_PTR->PDIRs.PDIR24
#define PTE25_IN    PTE_BASE_PTR->PDIRs.PDIR25
#define PTE26_IN    PTE_BASE_PTR->PDIRs.PDIR26
#define PTE27_IN    PTE_BASE_PTR->PDIRs.PDIR27
#define PTE28_IN    PTE_BASE_PTR->PDIRs.PDIR28
#define PTE29_IN    PTE_BASE_PTR->PDIRs.PDIR29
#define PTE30_IN    PTE_BASE_PTR->PDIRs.PDIR30
#define PTE31_IN    PTE_BASE_PTR->PDIRs.PDIR31



//定义PTA的8位端口  ——by 野火
#define PTA_BYTE0_OUT   PTA_BASE_PTR->PDORByte.Byte0
#define PTA_BYTE1_OUT   PTA_BASE_PTR->PDORByte.Byte1
#define PTA_BYTE2_OUT   PTA_BASE_PTR->PDORByte.Byte2
#define PTA_BYTE3_OUT   PTA_BASE_PTR->PDORByte.Byte3

//定义PTB的8位端口  ——by 野火
#define PTB_BYTE0_OUT   PTB_BASE_PTR->PDORByte.Byte0
#define PTB_BYTE1_OUT   PTB_BASE_PTR->PDORByte.Byte1
#define PTB_BYTE2_OUT   PTB_BASE_PTR->PDORByte.Byte2
#define PTB_BYTE3_OUT   PTB_BASE_PTR->PDORByte.Byte3


//定义PTC的8位端口  ——by 野火
#define PTC_BYTE0_OUT   PTC_BASE_PTR->PDORByte.Byte0
#define PTC_BYTE1_OUT   PTC_BASE_PTR->PDORByte.Byte1
#define PTC_BYTE2_OUT   PTC_BASE_PTR->PDORByte.Byte2
#define PTC_BYTE3_OUT   PTC_BASE_PTR->PDORByte.Byte3

//定义PTD的8位端口  ——by 野火
#define PTD_BYTE0_OUT   PTD_BASE_PTR->PDORByte.Byte0
#define PTD_BYTE1_OUT   PTD_BASE_PTR->PDORByte.Byte1
#define PTD_BYTE2_OUT   PTD_BASE_PTR->PDORByte.Byte2
#define PTD_BYTE3_OUT   PTD_BASE_PTR->PDORByte.Byte3

//定义PTE的8位端口  ——by 野火
#define PTE_BYTE0_OUT   PTE_BASE_PTR->PDORByte.Byte0
#define PTE_BYTE1_OUT   PTE_BASE_PTR->PDORByte.Byte1
#define PTE_BYTE2_OUT   PTE_BASE_PTR->PDORByte.Byte2
#define PTE_BYTE3_OUT   PTE_BASE_PTR->PDORByte.Byte3


//定义PTA的8位输出输入方向  ——by 野火
#define DDRA_BYTE0   PTA_BASE_PTR->DDRByte.Byte0
#define DDRA_BYTE1   PTA_BASE_PTR->DDRByte.Byte1
#define DDRA_BYTE2   PTA_BASE_PTR->DDRByte.Byte2
#define DDRA_BYTE3   PTA_BASE_PTR->DDRByte.Byte3

//定义PTB的8位输出输入方向  ——by 野火
#define DDRB_BYTE0   PTB_BASE_PTR->DDRByte.Byte0
#define DDRB_BYTE1   PTB_BASE_PTR->DDRByte.Byte1
#define DDRB_BYTE2   PTB_BASE_PTR->DDRByte.Byte2
#define DDRB_BYTE3   PTB_BASE_PTR->DDRByte.Byte3

//定义PTC的8位输出输入方向  ——by 野火
#define DDRC_BYTE0   PTC_BASE_PTR->DDRByte.Byte0
#define DDRC_BYTE1   PTC_BASE_PTR->DDRByte.Byte1
#define DDRC_BYTE2   PTC_BASE_PTR->DDRByte.Byte2
#define DDRC_BYTE3   PTC_BASE_PTR->DDRByte.Byte3

//定义PTD的8位输出输入方向  ——by 野火
#define DDRD_BYTE0   PTD_BASE_PTR->DDRByte.Byte0
#define DDRD_BYTE1   PTD_BASE_PTR->DDRByte.Byte1
#define DDRD_BYTE2   PTD_BASE_PTR->DDRByte.Byte2
#define DDRD_BYTE3   PTD_BASE_PTR->DDRByte.Byte3

//定义PTE的8位输出输入方向  ——by 野火
#define DDRE_BYTE0   PTE_BASE_PTR->DDRByte.Byte0
#define DDRE_BYTE1   PTE_BASE_PTR->DDRByte.Byte1
#define DDRE_BYTE2   PTE_BASE_PTR->DDRByte.Byte2
#define DDRE_BYTE3   PTE_BASE_PTR->DDRByte.Byte3


//定义PTA的8位输入端口  ——by 野火
#define PTA_BYTE0_IN   PTA_BASE_PTR->PDIRByte.Byte0
#define PTA_BYTE1_IN   PTA_BASE_PTR->PDIRByte.Byte1
#define PTA_BYTE2_IN   PTA_BASE_PTR->PDIRByte.Byte2
#define PTA_BYTE3_IN   PTA_BASE_PTR->PDIRByte.Byte3

//定义PTB的8位输入端口  ——by 野火
#define PTB_BYTE0_IN   PTB_BASE_PTR->PDIRByte.Byte0
#define PTB_BYTE1_IN   PTB_BASE_PTR->PDIRByte.Byte1
#define PTB_BYTE2_IN   PTB_BASE_PTR->PDIRByte.Byte2
#define PTB_BYTE3_IN   PTB_BASE_PTR->PDIRByte.Byte3

//定义PTC的8位输入端口  ——by 野火
#define PTC_BYTE0_IN   PTC_BASE_PTR->PDIRByte.Byte0
#define PTC_BYTE1_IN   PTC_BASE_PTR->PDIRByte.Byte1
#define PTC_BYTE2_IN   PTC_BASE_PTR->PDIRByte.Byte2
#define PTC_BYTE3_IN   PTC_BASE_PTR->PDIRByte.Byte3


//定义PTD的8位输入端口  ——by 野火
#define PTD_BYTE0_IN   PTD_BASE_PTR->PDIRByte.Byte0
#define PTD_BYTE1_IN   PTD_BASE_PTR->PDIRByte.Byte1
#define PTD_BYTE2_IN   PTD_BASE_PTR->PDIRByte.Byte2
#define PTD_BYTE3_IN   PTD_BASE_PTR->PDIRByte.Byte3

//定义PTE的8位输入端口  ——by 野火
#define PTE_BYTE0_IN   PTE_BASE_PTR->PDIRByte.Byte0
#define PTE_BYTE1_IN   PTE_BASE_PTR->PDIRByte.Byte1
#define PTE_BYTE2_IN   PTE_BASE_PTR->PDIRByte.Byte2
#define PTE_BYTE3_IN   PTE_BASE_PTR->PDIRByte.Byte3

//定义PTA的16位端口  ——by 野火
#define PTA_WORD0_OUT   PTA_BASE_PTR->PDORWord.Word0
#define PTA_WORD1_OUT   PTA_BASE_PTR->PDORWord.Word1

//定义PTB的16位端口  ——by 野火
#define PTB_WORD0_OUT   PTB_BASE_PTR->PDORWord.Word0
#define PTB_WORD1_OUT   PTB_BASE_PTR->PDORWord.Word1

//定义PTC的16位端口  ——by 野火
#define PTC_WORD0_OUT   PTC_BASE_PTR->PDORWord.Word0
#define PTC_WORD1_OUT   PTC_BASE_PTR->PDORWord.Word1


//定义PTD的16位端口  ——by 野火
#define PTD_WORD0_OUT   PTD_BASE_PTR->PDORWord.Word0
#define PTD_WORD1_OUT   PTD_BASE_PTR->PDORWord.Word1


//定义PTE的16位端口  ——by 野火
#define PTE_WORD0_OUT   PTE_BASE_PTR->PDORWord.Word0
#define PTE_WORD1_OUT   PTE_BASE_PTR->PDORWord.Word1


//定义PTA的16位输出输入方向  ——by 野火
#define DDRA_WORD0   PTA_BASE_PTR->DDRWord.Word0
#define DDRA_WORD1   PTA_BASE_PTR->DDRWord.Word1


//定义PTB的16位输出输入方向  ——by 野火
#define DDRB_WORD0   PTB_BASE_PTR->DDRWord.Word0
#define DDRB_WORD1   PTB_BASE_PTR->DDRWord.Word1


//定义PTC的16位输出输入方向  ——by 野火
#define DDRC_WORD0   PTC_BASE_PTR->DDRWord.Word0
#define DDRC_WORD1   PTC_BASE_PTR->DDRWord.Word1


//定义PTD的16位输出输入方向  ——by 野火
#define DDRD_WORD0   PTD_BASE_PTR->DDRWord.Word0
#define DDRD_WORD1   PTD_BASE_PTR->DDRWord.Word1


//定义PTE的16位输出输入方向  ——by 野火
#define DDRE_WORD0   PTE_BASE_PTR->DDRWord.Word0
#define DDRE_WORD1   PTE_BASE_PTR->DDRWord.Word1


//定义PTA的16位输入端口  ——by 野火
#define PTA_WORD0_IN   PTA_BASE_PTR->PDIRWord.Word0
#define PTA_WORD1_IN   PTA_BASE_PTR->PDIRWord.Word1


//定义PTB的16位输入端口  ——by 野火
#define PTB_WORD0_IN   PTB_BASE_PTR->PDIRWord.Word0
#define PTB_WORD1_IN   PTB_BASE_PTR->PDIRWord.Word1

//定义PTC的16位输入端口  ——by 野火
#define PTC_WORD0_IN   PTC_BASE_PTR->PDIRWord.Word0
#define PTC_WORD1_IN   PTC_BASE_PTR->PDIRWord.Word1


//定义PTD的16位输入端口  ——by 野火
#define PTD_WORD0_IN   PTD_BASE_PTR->PDIRWord.Word0
#define PTD_WORD1_IN   PTD_BASE_PTR->PDIRWord.Word1


//定义PTE的16位输入端口  ——by 野火
#define PTE_WORD0_IN   PTE_BASE_PTR->PDIRWord.Word0
#define PTE_WORD1_IN   PTE_BASE_PTR->PDIRWord.Word1


typedef enum PTxn
{
/*  PTA端口    */
    PTA0,
    PTA1,
    PTA2,
    PTA3,
    PTA4,
    PTA5,
    PTA6,
    PTA7,
    PTA8,
    PTA9,
    PTA10,
    PTA11,
    PTA12,
    PTA13,
    PTA14,
    PTA15,
    PTA16,
    PTA17,
    PTA18,
    PTA19,
    PTA20,
    PTA21,
    PTA22,
    PTA23,
    PTA24,
    PTA25,
    PTA26,
    PTA27,
    PTA28,
    PTA29,
    PTA30,
    PTA31,

/*  PTB端口    */
    PTB0,
    PTB1,
    PTB2,
    PTB3,
    PTB4,
    PTB5,
    PTB6,
    PTB7,
    PTB8,
    PTB9,
    PTB10,
    PTB11,
    PTB12,
    PTB13,
    PTB14,
    PTB15,
    PTB16,
    PTB17,
    PTB18,
    PTB19,
    PTB20,
    PTB21,
    PTB22,
    PTB23,
    PTB24,
    PTB25,
    PTB26,
    PTB27,
    PTB28,
    PTB29,
    PTB30,
    PTB31,

/*  PTC端口    */
    PTC0,
    PTC1,
    PTC2,
    PTC3,
    PTC4,
    PTC5,
    PTC6,
    PTC7,
    PTC8,
    PTC9,
    PTC10,
    PTC11,
    PTC12,
    PTC13,
    PTC14,
    PTC15,
    PTC16,
    PTC17,
    PTC18,
    PTC19,
    PTC20,
    PTC21,
    PTC22,
    PTC23,
    PTC24,
    PTC25,
    PTC26,
    PTC27,
    PTC28,
    PTC29,
    PTC30,
    PTC31,

/*  PTD端口    */
    PTD0,
    PTD1,
    PTD2,
    PTD3,
    PTD4,
    PTD5,
    PTD6,
    PTD7,
    PTD8,
    PTD9,
    PTD10,
    PTD11,
    PTD12,
    PTD13,
    PTD14,
    PTD15,
    PTD16,
    PTD17,
    PTD18,
    PTD19,
    PTD20,
    PTD21,
    PTD22,
    PTD23,
    PTD24,
    PTD25,
    PTD26,
    PTD27,
    PTD28,
    PTD29,
    PTD30,
    PTD31,

/*  PTE端口    */
    PTE0,
    PTE1,
    PTE2,
    PTE3,
    PTE4,
    PTE5,
    PTE6,
    PTE7,
    PTE8,
    PTE9,
    PTE10,
    PTE11,
    PTE12,
    PTE13,
    PTE14,
    PTE15,
    PTE16,
    PTE17,
    PTE18,
    PTE19,
    PTE20,
    PTE21,
    PTE22,
    PTE23,
    PTE24,
    PTE25,
    PTE26,
    PTE27,
    PTE28,
    PTE29,
    PTE30,
    PTE31,

} PTxn;

//定义PTA的翻转电平输出端口
#define PTA0_T            PT(A,0,PTOR)
#define PTA1_T            PT(A,1,PTOR)
#define PTA2_T            PT(A,2,PTOR)
#define PTA3_T            PT(A,3,PTOR)
#define PTA4_T            PT(A,4,PTOR)
#define PTA5_T            PT(A,5,PTOR)
#define PTA6_T            PT(A,6,PTOR)
#define PTA7_T            PT(A,7,PTOR)
#define PTA8_T            PT(A,8,PTOR)
#define PTA9_T            PT(A,9,PTOR)
#define PTA10_T           PT(A,10,PTOR)
#define PTA11_T           PT(A,11,PTOR)
#define PTA12_T           PT(A,12,PTOR)
#define PTA13_T           PT(A,13,PTOR)
#define PTA14_T           PT(A,14,PTOR)
#define PTA15_T           PT(A,15,PTOR)
#define PTA16_T           PT(A,16,PTOR)
#define PTA17_T           PT(A,17,PTOR)
#define PTA18_T           PT(A,18,PTOR)
#define PTA19_T           PT(A,19,PTOR)
#define PTA20_T           PT(A,20,PTOR)
#define PTA21_T           PT(A,21,PTOR)
#define PTA22_T           PT(A,22,PTOR)
#define PTA23_T           PT(A,23,PTOR)
#define PTA24_T           PT(A,24,PTOR)
#define PTA25_T           PT(A,25,PTOR)
#define PTA26_T           PT(A,26,PTOR)
#define PTA27_T           PT(A,27,PTOR)
#define PTA28_T           PT(A,28,PTOR)
#define PTA29_T           PT(A,29,PTOR)
#define PTA30_T           PT(A,30,PTOR)
#define PTA31_T           PT(A,31,PTOR)

//定义PTB的翻转电平输出端口
#define PTB0_T           PT(B,0,PTOR)
#define PTB1_T           PT(B,1,PTOR)
#define PTB2_T           PT(B,2,PTOR)
#define PTB3_T           PT(B,3,PTOR)
#define PTB4_T           PT(B,4,PTOR)
#define PTB5_T           PT(B,5,PTOR)
#define PTB6_T           PT(B,6,PTOR)
#define PTB7_T           PT(B,7,PTOR)
#define PTB8_T           PT(B,8,PTOR)
#define PTB9_T           PT(B,9,PTOR)
#define PTB10_T           PT(B,10,PTOR)
#define PTB11_T           PT(B,11,PTOR)
#define PTB12_T           PT(B,12,PTOR)
#define PTB13_T           PT(B,13,PTOR)
#define PTB14_T           PT(B,14,PTOR)
#define PTB15_T           PT(B,15,PTOR)
#define PTB16_T           PT(B,16,PTOR)
#define PTB17_T           PT(B,17,PTOR)
#define PTB18_T           PT(B,18,PTOR)
#define PTB19_T           PT(B,19,PTOR)
#define PTB20_T           PT(B,20,PTOR)
#define PTB21_T           PT(B,21,PTOR)
#define PTB22_T           PT(B,22,PTOR)
#define PTB23_T           PT(B,23,PTOR)
#define PTB24_T           PT(B,24,PTOR)
#define PTB25_T           PT(B,25,PTOR)
#define PTB26_T           PT(B,26,PTOR)
#define PTB27_T           PT(B,27,PTOR)
#define PTB28_T           PT(B,28,PTOR)
#define PTB29_T           PT(B,29,PTOR)
#define PTB30_T           PT(B,30,PTOR)
#define PTB31_T           PT(B,31,PTOR)

//定义PTC的翻转电平输出端口
#define PTC0_T           PT(C,0,PTOR)
#define PTC1_T           PT(C,1,PTOR)
#define PTC2_T           PT(C,2,PTOR)
#define PTC3_T           PT(C,3,PTOR)
#define PTC4_T           PT(C,4,PTOR)
#define PTC5_T           PT(C,5,PTOR)
#define PTC6_T           PT(C,6,PTOR)
#define PTC7_T           PT(C,7,PTOR)
#define PTC8_T           PT(C,8,PTOR)
#define PTC9_T           PT(C,9,PTOR)
#define PTC10_T           PT(C,10,PTOR)
#define PTC11_T           PT(C,11,PTOR)
#define PTC12_T           PT(C,12,PTOR)
#define PTC13_T           PT(C,13,PTOR)
#define PTC14_T           PT(C,14,PTOR)
#define PTC15_T           PT(C,15,PTOR)
#define PTC16_T           PT(C,16,PTOR)
#define PTC17_T           PT(C,17,PTOR)
#define PTC18_T           PT(C,18,PTOR)
#define PTC19_T           PT(C,19,PTOR)
#define PTC20_T           PT(C,20,PTOR)
#define PTC21_T           PT(C,21,PTOR)
#define PTC22_T           PT(C,22,PTOR)
#define PTC23_T           PT(C,23,PTOR)
#define PTC24_T           PT(C,24,PTOR)
#define PTC25_T           PT(C,25,PTOR)
#define PTC26_T           PT(C,26,PTOR)
#define PTC27_T           PT(C,27,PTOR)
#define PTC28_T           PT(C,28,PTOR)
#define PTC29_T           PT(C,29,PTOR)
#define PTC30_T           PT(C,30,PTOR)
#define PTC31_T           PT(C,31,PTOR)

//定义PTD的翻转电平输出端口
#define PTD0_T           PT(D,0,PTOR)
#define PTD1_T           PT(D,1,PTOR)
#define PTD2_T           PT(D,2,PTOR)
#define PTD3_T           PT(D,3,PTOR)
#define PTD4_T           PT(D,4,PTOR)
#define PTD5_T           PT(D,5,PTOR)
#define PTD6_T           PT(D,6,PTOR)
#define PTD7_T           PT(D,7,PTOR)
#define PTD8_T           PT(D,8,PTOR)
#define PTD9_T           PT(D,9,PTOR)
#define PTD10_T           PT(D,10,PTOR)
#define PTD11_T           PT(D,11,PTOR)
#define PTD12_T           PT(D,12,PTOR)
#define PTD13_T           PT(D,13,PTOR)
#define PTD14_T           PT(D,14,PTOR)
#define PTD15_T           PT(D,15,PTOR)
#define PTD16_T           PT(D,16,PTOR)
#define PTD17_T           PT(D,17,PTOR)
#define PTD18_T           PT(D,18,PTOR)
#define PTD19_T           PT(D,19,PTOR)
#define PTD20_T           PT(D,20,PTOR)
#define PTD21_T           PT(D,21,PTOR)
#define PTD22_T           PT(D,22,PTOR)
#define PTD23_T           PT(D,23,PTOR)
#define PTD24_T           PT(D,24,PTOR)
#define PTD25_T           PT(D,25,PTOR)
#define PTD26_T           PT(D,26,PTOR)
#define PTD27_T           PT(D,27,PTOR)
#define PTD28_T           PT(D,28,PTOR)
#define PTD29_T           PT(D,29,PTOR)
#define PTD30_T           PT(D,30,PTOR)
#define PTD31_T           PT(D,31,PTOR)

//定义PTE的翻转电平输出端口
#define PTE0_T           PT(E,0,PTOR)
#define PTE1_T           PT(E,1,PTOR)
#define PTE2_T           PT(E,2,PTOR)
#define PTE3_T           PT(E,3,PTOR)
#define PTE4_T           PT(E,4,PTOR)
#define PTE5_T           PT(E,5,PTOR)
#define PTE6_T           PT(E,6,PTOR)
#define PTE7_T           PT(E,7,PTOR)
#define PTE8_T           PT(E,8,PTOR)
#define PTE9_T           PT(E,9,PTOR)
#define PTE10_T           PT(E,10,PTOR)
#define PTE11_T           PT(E,11,PTOR)
#define PTE12_T           PT(E,12,PTOR)
#define PTE13_T           PT(E,13,PTOR)
#define PTE14_T           PT(E,14,PTOR)
#define PTE15_T           PT(E,15,PTOR)
#define PTE16_T           PT(E,16,PTOR)
#define PTE17_T           PT(E,17,PTOR)
#define PTE18_T           PT(E,18,PTOR)
#define PTE19_T           PT(E,19,PTOR)
#define PTE20_T           PT(E,20,PTOR)
#define PTE21_T           PT(E,21,PTOR)
#define PTE22_T           PT(E,22,PTOR)
#define PTE23_T           PT(E,23,PTOR)
#define PTE24_T           PT(E,24,PTOR)
#define PTE25_T           PT(E,25,PTOR)
#define PTE26_T           PT(E,26,PTOR)
#define PTE27_T           PT(E,27,PTOR)
#define PTE28_T           PT(E,28,PTOR)
#define PTE29_T           PT(E,29,PTOR)
#define PTE30_T           PT(E,30,PTOR)
#define PTE31_T           PT(E,31,PTOR)


//定义PTA的8位端口
#define PTA_B0_OUT        PT_BYTE(A,0,PDOR)
#define PTA_B1_OUT        PT_BYTE(A,1,PDOR)
#define PTA_B2_OUT        PT_BYTE(A,2,PDOR)
#define PTA_B3_OUT        PT_BYTE(A,3,PDOR)

//定义PTB的8位端口
#define PTB_B0_OUT        PT_BYTE(B,0,PDOR)
#define PTB_B1_OUT        PT_BYTE(B,1,PDOR)
#define PTB_B2_OUT        PT_BYTE(B,2,PDOR)
#define PTB_B3_OUT        PT_BYTE(B,3,PDOR)


//定义PTC的8位端口
#define PTC_B0_OUT        PT_BYTE(C,0,PDOR)
#define PTC_B1_OUT        PT_BYTE(C,1,PDOR)
#define PTC_B2_OUT        PT_BYTE(C,2,PDOR)
#define PTC_B3_OUT        PT_BYTE(C,3,PDOR)

//定义PTD的8位端口
#define PTD_B0_OUT        PT_BYTE(D,0,PDOR)
#define PTD_B1_OUT        PT_BYTE(D,1,PDOR)
#define PTD_B2_OUT        PT_BYTE(D,2,PDOR)
#define PTD_B3_OUT        PT_BYTE(D,3,PDOR)

//定义PTE的8位端口
#define PTE_B0_OUT        PT_BYTE(E,0,PDOR)
#define PTE_B1_OUT        PT_BYTE(E,1,PDOR)
#define PTE_B2_OUT        PT_BYTE(E,2,PDOR)
#define PTE_B3_OUT        PT_BYTE(E,3,PDOR)



//定义PTA的8位输出输入方向端口
#define PTA_B0_DDR        PT_BYTE(A,0,PDDR)
#define PTA_B1_DDR        PT_BYTE(A,1,PDDR)
#define PTA_B2_DDR        PT_BYTE(A,2,PDDR)
#define PTA_B3_DDR        PT_BYTE(A,3,PDDR)

//定义PTB的8位输出输入方向端口
#define PTB_B0_DDR        PT_BYTE(B,0,PDDR)
#define PTB_B1_DDR        PT_BYTE(B,1,PDDR)
#define PTB_B2_DDR        PT_BYTE(B,2,PDDR)
#define PTB_B3_DDR        PT_BYTE(B,3,PDDR)


//定义PTC的8位输出输入方向端口
#define PTC_B0_DDR        PT_BYTE(C,0,PDDR)
#define PTC_B1_DDR        PT_BYTE(C,1,PDDR)
#define PTC_B2_DDR        PT_BYTE(C,2,PDDR)
#define PTC_B3_DDR        PT_BYTE(C,3,PDDR)

//定义PTD的8位输出输入方向端口
#define PTD_B0_DDR        PT_BYTE(D,0,PDDR)
#define PTD_B1_DDR        PT_BYTE(D,1,PDDR)
#define PTD_B2_DDR        PT_BYTE(D,2,PDDR)
#define PTD_B3_DDR        PT_BYTE(D,3,PDDR)

//定义PTE的8位输出输入方向端口
#define PTE_B0_DDR        PT_BYTE(E,0,PDDR)
#define PTE_B1_DDR        PT_BYTE(E,1,PDDR)
#define PTE_B2_DDR        PT_BYTE(E,2,PDDR)
#define PTE_B3_DDR        PT_BYTE(E,3,PDDR)



//定义PTA的8位输入端口
#define PTA_B0_IN        PT_BYTE(A,0,PDIR)
#define PTA_B1_IN        PT_BYTE(A,1,PDIR)
#define PTA_B2_IN        PT_BYTE(A,2,PDIR)
#define PTA_B3_IN        PT_BYTE(A,3,PDIR)

//定义PTB的8位输入端口
#define PTB_B0_IN        PT_BYTE(B,0,PDIR)
#define PTB_B1_IN        PT_BYTE(B,1,PDIR)
#define PTB_B2_IN        PT_BYTE(B,2,PDIR)
#define PTB_B3_IN        PT_BYTE(B,3,PDIR)


//定义PTC的8位输入端口
#define PTC_B0_IN        PT_BYTE(C,0,PDIR)
#define PTC_B1_IN        PT_BYTE(C,1,PDIR)
#define PTC_B2_IN        PT_BYTE(C,2,PDIR)
#define PTC_B3_IN        PT_BYTE(C,3,PDIR)

//定义PTD的8位输入端口
#define PTD_B0_IN        PT_BYTE(D,0,PDIR)
#define PTD_B1_IN        PT_BYTE(D,1,PDIR)
#define PTD_B2_IN        PT_BYTE(D,2,PDIR)
#define PTD_B3_IN        PT_BYTE(D,3,PDIR)

//定义PTE的8位输入端口
#define PTE_B0_IN        PT_BYTE(E,0,PDIR)
#define PTE_B1_IN        PT_BYTE(E,1,PDIR)
#define PTE_B2_IN        PT_BYTE(E,2,PDIR)
#define PTE_B3_IN        PT_BYTE(E,3,PDIR)


//定义PTA的8位输出反转
#define PTA_B0_T        PT_BYTE(A,0,PTOR)
#define PTA_B1_T        PT_BYTE(A,1,PTOR)
#define PTA_B2_T        PT_BYTE(A,2,PTOR)
#define PTA_B3_T        PT_BYTE(A,3,PTOR)

//定义PTB的8位输出反转
#define PTB_B0_T        PT_BYTE(B,0,PTOR)
#define PTB_B1_T        PT_BYTE(B,1,PTOR)
#define PTB_B2_T        PT_BYTE(B,2,PTOR)
#define PTB_B3_T        PT_BYTE(B,3,PTOR)


//定义PTC的8位输出反转
#define PTC_B0_T        PT_BYTE(C,0,PTOR)
#define PTC_B1_T        PT_BYTE(C,1,PTOR)
#define PTC_B2_T        PT_BYTE(C,2,PTOR)
#define PTC_B3_T        PT_BYTE(C,3,PTOR)

//定义PTD的8位输出反转
#define PTD_B0_T        PT_BYTE(D,0,PTOR)
#define PTD_B1_T        PT_BYTE(D,1,PTOR)
#define PTD_B2_T        PT_BYTE(D,2,PTOR)
#define PTD_B3_T        PT_BYTE(D,3,PTOR)

//定义PTE的8位输出反转
#define PTE_B0_T        PT_BYTE(E,0,PTOR)
#define PTE_B1_T        PT_BYTE(E,1,PTOR)
#define PTE_B2_T        PT_BYTE(E,2,PTOR)
#define PTE_B3_T        PT_BYTE(E,3,PTOR)


//定义PTA的16位端口
#define PTA_W0_OUT        PT_WORD(A,0,PDOR)
#define PTA_W1_OUT        PT_WORD(A,1,PDOR)

//定义PTB的16位端口
#define PTB_W0_OUT        PT_WORD(B,0,PDOR)
#define PTB_W1_OUT        PT_WORD(B,1,PDOR)

//定义PTC的16位端口
#define PTC_W0_OUT        PT_WORD(C,0,PDOR)
#define PTC_W1_OUT        PT_WORD(C,1,PDOR)


//定义PTD的16位端口
#define PTD_W0_OUT        PT_WORD(D,0,PDOR)
#define PTD_W1_OUT        PT_WORD(D,1,PDOR)


//定义PTE的16位端口
#define PTE_W0_OUT        PT_WORD(E,0,PDOR)
#define PTE_W1_OUT        PT_WORD(E,1,PDOR)


//定义PTA的16位输出输入方向端口
#define PTA_W0_DDR        PT_WORD(A,0,PDDR)
#define PTA_W1_DDR        PT_WORD(A,1,PDDR)

//定义PTB的16位输出输入方向端口
#define PTB_W0_DDR        PT_WORD(B,0,PDDR)
#define PTB_W1_DDR        PT_WORD(B,1,PDDR)

//定义PTC的16位输出输入方向端口
#define PTC_W0_DDR        PT_WORD(C,0,PDDR)
#define PTC_W1_DDR        PT_WORD(C,1,PDDR)


//定义PTD的16位输出输入方向端口
#define PTD_W0_DDR        PT_WORD(D,0,PDDR)
#define PTD_W1_DDR        PT_WORD(D,1,PDDR)


//定义PTE的16位输出输入方向端口
#define PTE_W0_DDR        PT_WORD(E,0,PDDR)
#define PTE_W1_DDR        PT_WORD(E,1,PDDR)



//定义PTA的16位输入端口
#define PTA_W0_IN        PT_WORD(A,0,PDIR)
#define PTA_W1_IN        PT_WORD(A,1,PDIR)

//定义PTB的16位输入端口
#define PTB_W0_IN        PT_WORD(B,0,PDIR)
#define PTB_W1_IN        PT_WORD(B,1,PDIR)

//定义PTC的16位输入端口
#define PTC_W0_IN        PT_WORD(C,0,PDIR)
#define PTC_W1_IN        PT_WORD(C,1,PDIR)


//定义PTD的16位输入端口
#define PTD_W0_IN        PT_WORD(D,0,PDIR)
#define PTD_W1_IN        PT_WORD(D,1,PDIR)


//定义PTE的16位输入端口
#define PTE_W0_IN        PT_WORD(E,0,PDIR)
#define PTE_W1_IN        PT_WORD(E,1,PDIR)


//定义PTA的16位输出反转
#define PTA_W0_T        PT_WORD(A,0,PTOR)
#define PTA_W1_T        PT_WORD(A,1,PTOR)

//定义PTB的16位输出反转
#define PTB_W0_T        PT_WORD(B,0,PTOR)
#define PTB_W1_T        PT_WORD(B,1,PTOR)

//定义PTC的16位输出反转
#define PTC_W0_T        PT_WORD(C,0,PTOR)
#define PTC_W1_T        PT_WORD(C,1,PTOR)


//定义PTD的16位输出反转
#define PTD_W0_T        PT_WORD(D,0,PTOR)
#define PTD_W1_T        PT_WORD(D,1,PTOR)


//定义PTE的16位输出反转
#define PTE_W0_T        PT_WORD(E,0,PTOR)
#define PTE_W1_T        PT_WORD(E,1,PTOR)


//定义32位端口输出
#define PTA_OUT          PT_DWORD(A,PDOR)
#define PTB_OUT          PT_DWORD(B,PDOR)
#define PTC_OUT          PT_DWORD(C,PDOR)
#define PTD_OUT          PT_DWORD(D,PDOR)
#define PTE_OUT          PT_DWORD(E,PDOR)

//定义32位端口输入
#define PTA_IN          PT_DWORD(A,PDIR)
#define PTB_IN          PT_DWORD(B,PDIR)
#define PTC_IN          PT_DWORD(C,PDIR)
#define PTD_IN          PT_DWORD(D,PDIR)
#define PTE_IN          PT_DWORD(E,PDIR)

//定义32位端口输出输出方向
#define PTA_DDR          PT_DWORD(A,PDDR)
#define PTB_DDR          PT_DWORD(B,PDDR)
#define PTC_DDR          PT_DWORD(C,PDDR)
#define PTD_DDR          PT_DWORD(D,PDDR)
#define PTE_DDR          PT_DWORD(E,PDDR)

//定义32位输出反转
#define PTA_T          PT_DWORD(A,PTOR)
#define PTB_T          PT_DWORD(B,PTOR)
#define PTC_T          PT_DWORD(C,PTOR)
#define PTD_T          PT_DWORD(D,PTOR)
#define PTE_T          PT_DWORD(E,PTOR)

#endif
