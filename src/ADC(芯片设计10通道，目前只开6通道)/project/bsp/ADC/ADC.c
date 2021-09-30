#include "Tk499.h"
#include "sys.h"
#include "stdio.h"
#include "ADC.h"

void ADC_Config(void)
{
	volatile int i;

	GPIO_InitTypeDef GPIO_InitStructure;//����GPIO��ʼ���ṹ�����
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_AHBPeriph_GPIOB, ENABLE);
	//����ADC����Ϊģ������ģʽ
	GPIO_InitStructure.GPIO_Pin    =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_AIN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	RCC->APB2ENR |= 0x1<<25;  //��ADCʱ�ӣ���touchpad����ʱ��
	TOUCHPAD->ADCFG =0x3E1E70;      //16��Ƶ   AD�Ƚ�������
	TOUCHPAD->ADCR = 0x400;      //0x200������ģʽ;0x400����ɨ��ģʽ
	TOUCHPAD->ADCHS = 0x3F;      //ͨ��ʹ�� 0~5����6��ͨ��
	TOUCHPAD->ADCFG |= 0x1;      //ADCʹ��
	TOUCHPAD->ADCR |= 0x1<<8;  //A/Dת����ʼ (ADC start)

//	TOUCHPAD->ADCR |=0x1;        //ʹ��ADC�ж�
}
//int ADC_AN0,ADC_AN1;
//void TOUCHPAD_IRQHandler()
//{

////	if(TOUCHPAD->TPCR & (0x1<<16))
////	{

//		ADC_AN0 = TOUCHPAD->ADDR4;
//		ADC_AN1 = TOUCHPAD->ADDR5;
//		printf("\r\n  AN0= %x  \r\n",ADC_AN0);//��ӡAN0��ADC����ֵ
//		printf("\r\n  AN1= %x  \r\n",ADC_AN1);//��ӡAN1��ADC����ֵ
//		TOUCHPAD->ADCR |=0x1;//����ʹ��A/D�ж�
//	TOUCHPAD->ADCR |= 0x1<<8;  //A/Dת����ʼ (ADC start)
////	}

//}
