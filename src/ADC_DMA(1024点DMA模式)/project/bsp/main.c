/****************************************Copyright (c)****************************************************
** 
**                                      
**
**--------------File Info---------------------------------------------------------------------------------
** File name:			main.c
** modified Date:  		2019-8-12
** Last Version:		V0.1
** Descriptions:		  main 函数调用
** Author : xiao chen
** Historical Version :
** 好钜润科技，芯片事业部----深圳龙华应用分部
*********************************************************************************************************/
#include "HAL_conf.h"
#include "UART.h"
#include "sys.h"
#include "timer.h"
#include "GPIO.h"
#include "ADC.h"
/********************************************************************************************************
**函数信息 ：int main (void)                          
**功能描述 ：
**输入参数 ：
**输出参数 ：
********************************************************************************************************/
extern  u16 ADCValue[1024];
extern u8 ADCflag;
int main(void)
{
	int i;
	RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_20);//启动PLL时钟，频率为12MHz*20=240MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2：2，全局性函数，仅需设置一次
	LED_Init();								   //LED初始化
	UartInit(UART1,460800);      //串口初始化，波特率是460800
	printf(" welcome to use TK499!\r\n");								
//	TIM8_Config(3000,24000);     //配置定时器8，在定时器中断里闪PA15引脚上的LED灯，0.3秒中断一次
	
	ADC_Config();//配置ADC
	DMAInit();
	while(1)    //无限循环
	{
//		if(((TOUCHPAD->ADDR4)>>20)==3)//判断是否是有效采样
		if(ADCflag)//DMA转换结束
		{
			for(i=0;i<1024;i++)
			{
				printf("\r\n  ADCValue_%d= %x  \r\n",i,ADCValue[i]);//打印ADC4
			}
			ADCflag=0;
			TOUCHPAD->ADCR |= (0x1<<8);  // DMA使能
//		printf("\r\n  AN5= %x  \r\n",TOUCHPAD->ADDR5);//打印ADC5采样值
//		printf("\r\n");
		}

		i=5000000;while(--i);//延时
	}
}



