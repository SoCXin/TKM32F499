#include "Tk499.h"
#include "sys.h"
#include "stdio.h"
#include "ADC.h"

void ADC_Config(void)
{
	volatile int i;

	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_AHBPeriph_GPIOB, ENABLE);
	//配置ADC引脚为模拟输入模式
	GPIO_InitStructure.GPIO_Pin    =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_AIN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	RCC->APB2ENR |= 0x1<<25;  //打开ADC时钟，与touchpad共用时钟
	TOUCHPAD->ADCFG =0x3E1E70;      //16分频   AD比较器禁用
	TOUCHPAD->ADCR = 0x400;      //0x200单周期模式;0x400连续扫描模式
	TOUCHPAD->ADCHS = 0x3F;      //通道使能 0~5，共6个通道
	TOUCHPAD->ADCFG |= 0x1;      //ADC使能
	TOUCHPAD->ADCR |= 0x1<<8;  //A/D转换开始 (ADC start)

//	TOUCHPAD->ADCR |=0x1;        //使能ADC中断
}
//int ADC_AN0,ADC_AN1;
//void TOUCHPAD_IRQHandler()
//{

////	if(TOUCHPAD->TPCR & (0x1<<16))
////	{

//		ADC_AN0 = TOUCHPAD->ADDR4;
//		ADC_AN1 = TOUCHPAD->ADDR5;
//		printf("\r\n  AN0= %x  \r\n",ADC_AN0);//打印AN0的ADC采样值
//		printf("\r\n  AN1= %x  \r\n",ADC_AN1);//打印AN1的ADC采样值
//		TOUCHPAD->ADCR |=0x1;//重新使能A/D中断
//	TOUCHPAD->ADCR |= 0x1<<8;  //A/D转换开始 (ADC start)
////	}

//}
