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
extern  u16 ADCValue[1024];
extern u8 ADCflag;
int main(void)
{
	int i;
	RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_20);//����PLLʱ�ӣ�Ƶ��Ϊ12MHz*20=240MHz
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2��2��ȫ���Ժ�������������һ��
	LED_Init();								   //LED��ʼ��
	UartInit(UART1,460800);      //���ڳ�ʼ������������460800
	printf(" welcome to use TK499!\r\n");								
//	TIM8_Config(3000,24000);     //���ö�ʱ��8���ڶ�ʱ���ж�����PA15�����ϵ�LED�ƣ�0.3���ж�һ��
	
	ADC_Config();//����ADC
	DMAInit();
	while(1)    //����ѭ��
	{
//		if(((TOUCHPAD->ADDR4)>>20)==3)//�ж��Ƿ�����Ч����
		if(ADCflag)//DMAת������
		{
			for(i=0;i<1024;i++)
			{
				printf("\r\n  ADCValue_%d= %x  \r\n",i,ADCValue[i]);//��ӡADC4
			}
			ADCflag=0;
			TOUCHPAD->ADCR |= (0x1<<8);  // DMAʹ��
//		printf("\r\n  AN5= %x  \r\n",TOUCHPAD->ADDR5);//��ӡADC5����ֵ
//		printf("\r\n");
		}

		i=5000000;while(--i);//��ʱ
	}
}



