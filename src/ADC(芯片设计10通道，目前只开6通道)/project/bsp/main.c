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
#include "timer.h"
#include "GPIO.h"
#include "ADC.h"
/********************************************************************************************************
**������Ϣ ��int main (void)                          
**�������� ��
**������� ��
**������� ��
********************************************************************************************************/

int main(void)
{
	int i;
	RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_20);//����PLLʱ�ӣ�Ƶ��Ϊ12MHz*20=240MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2��2��ȫ���Ժ�������������һ��
	LED_Init();								   //LED��ʼ��
	UartInit(UART1,460800);      //���ڳ�ʼ������������460800
	printf(" welcome to use TK499!\r\n");								
	TIM8_Config(3000,24000);     //���ö�ʱ��8���ڶ�ʱ���ж�����PA15�����ϵ�LED�ƣ�0.3���ж�һ��
	
	ADC_Config();//����ADC
	while(1)    //����ѭ��
	{
		if(((TOUCHPAD->ADDR0)>>20)==3)//�ж��Ƿ�����Ч����
		{
			printf("\r\n  PB0_ADC0= %x  \r\n",TOUCHPAD->ADDR0);//��ӡADC0��ADC����ֵ
			printf("\r\n  PB1_ADC1= %x  \r\n",TOUCHPAD->ADDR1);//��ӡADC1��ADC����ֵ
			printf("\r\n  PB2_ADC2= %x  \r\n",TOUCHPAD->ADDR2);//��ӡADC2��ADC����ֵ
			printf("\r\n  PB3_ADC3= %x  \r\n",TOUCHPAD->ADDR3);//��ӡADC3��ADC����ֵ
			printf("\r\n  ADC4= %x  \r\n",TOUCHPAD->ADDR4);//��ӡADC4��ADC����ֵ
			printf("\r\n  ADC5= %x  \r\n",TOUCHPAD->ADDR5);//��ӡADC5��ADC����ֵ
			
			printf("\r\n");
		}

		i=5000000;while(--i);//��ʱ
	}
}



