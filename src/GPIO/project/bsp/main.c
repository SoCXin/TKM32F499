/****************************************Copyright (c)****************************************************
**
**
**
**--------------File Info---------------------------------------------------------------------------------
** File name:			main.c
** modified Date:  		2019-8-12
** Last Version:		V0.1
** Descriptions:		  main ��������
** Author : xiao chen
** Historical Version :
** ������Ƽ���оƬ��ҵ��----��������Ӧ�÷ֲ�
*********************************************************************************************************/
#include "HAL_conf.h"
#include "UART.h"
#include "sys.h"
#include "exit.h"
#include "key.h"
#include "LED.h"

/********************************************************************************************************
**������Ϣ ��int main (void)
**�������� ��
**������� ��
**������� ��
********************************************************************************************************/

//������ʵ�ֵĹ����ǣ��������򰴼����м���LED�����£�ͬʱ���ڴ�ӡ��Enter EXTI0_IRQHandler
int main(void)
{

	RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_20);//����PLLʱ�ӣ�12MHz*20=240MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2��2��ȫ���Ժ�������������һ��
	RemapVtorTable();

	//��������LED��GPIOΪ�������ģʽ
	LED_Init();					//LED��ʼ��

	UartInit(UART1,460800);     //UART1 ��ʼ�������ڽ��յ�ASCII�������ж�,��ӡ��ASCIIֵ
	printf(" welcome to use TK499!\r\n");
	printf("\r\n KEY IRQ Test \r\n");

	EXIT_KEY_Init();	//PA0 �жϰ�����ʼ��
	EXIT1_Init();			//PA1 �ⲿ�жϲ���
	EXIT8_Init();			//PA8 �ⲿ�жϲ���
	EXIT12_Init();		//PB12�ⲿ�жϲ���
	EXIT13_Init();		//PB13�ⲿ�жϲ���
	EXIT2_Init(); 		//PC2 �ⲿ�жϲ���
	EXIT7_Init();			//PD7 �ⲿ�жϲ���
	EXIT4_Init();			//PE4 �ⲿ�жϲ���

	while(1)//����ѭ��
	{
		// GPIO_SetBits(GPIOD, GPIO_Pin_8); //PC8����ߵ�ƽ������LED
		// for(i=0;i<2000000;i++);//��ʱ

		// GPIO_ResetBits(GPIOD, GPIO_Pin_8);//PD8����͵�ƽ��Ϩ��LED
		// for(i=0;i<2000000;i++);//��ʱ
	}
}






