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
#include "exit.h"
#include "key.h"
#include "LED.h"

/********************************************************************************************************
**函数信息 ：int main (void)
**功能描述 ：
**输入参数 ：
**输出参数 ：
********************************************************************************************************/

//本例程实现的功能是：按下五向按键的中键，LED闪两下，同时串口打印：Enter EXTI0_IRQHandler
int main(void)
{

	RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_20);//启动PLL时钟，12MHz*20=240MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2：2，全局性函数，仅需设置一次
	RemapVtorTable();

	//配置连接LED的GPIO为推挽输出模式
	LED_Init();					//LED初始化

	UartInit(UART1,460800);     //UART1 初始化，串口接收到ASCII码会进入中断,打印出ASCII值
	printf(" welcome to use TK499!\r\n");
	printf("\r\n KEY IRQ Test \r\n");

	EXIT_KEY_Init();	//PA0 中断按键初始化
	EXIT1_Init();			//PA1 外部中断测试
	EXIT8_Init();			//PA8 外部中断测试
	EXIT12_Init();		//PB12外部中断测试
	EXIT13_Init();		//PB13外部中断测试
	EXIT2_Init(); 		//PC2 外部中断测试
	EXIT7_Init();			//PD7 外部中断测试
	EXIT4_Init();			//PE4 外部中断测试

	while(1)//无限循环
	{
		// GPIO_SetBits(GPIOD, GPIO_Pin_8); //PC8输出高电平，点亮LED
		// for(i=0;i<2000000;i++);//延时

		// GPIO_ResetBits(GPIOD, GPIO_Pin_8);//PD8输出低电平，熄灭LED
		// for(i=0;i<2000000;i++);//延时
	}
}






