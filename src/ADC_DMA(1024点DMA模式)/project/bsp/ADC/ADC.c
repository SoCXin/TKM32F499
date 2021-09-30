#include "Tk499.h"
#include "sys.h"
#include "stdio.h"
#include "ADC.h"

//Used to store ADC conversion value
u16 ADCValue[1024];

//DMA transfer completed flag
u8 ADCflag;


void ADC_Config(void)
{
	volatile int i;
//	TK499_NVIC_Init(3,3,TOUCHPAD_IRQn,3);//抢占 1，子优先级 3，组 2	
	RCC->APB2ENR |= 0x1<<25;  //打开ADC时钟，与touchpad共用时钟

	TOUCHPAD->ADCFG =0x3E1E70;      //16分频   AD比较器禁用  21~17位，ADC预分频高8位，如果是触摸屏应用，应该分频大一些，手反应比较慢
	TOUCHPAD->ADCR = 0x400;      //0x200单周期模式;0x400连续扫描模式
	TOUCHPAD->ADCHS = 0x10;      //通道使能 4 通道
	TOUCHPAD->ADCFG |= 0x1;      //ADC使能
	TOUCHPAD->ADCR |= (0x1<<8)|(0x1<<3);  //A/D转换开始 (ADC start) DMA使能

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



/*******************************************************************************
* @name   : DMAInit
* @brief  : Initialize DMA
* @param  : None
* @retval : void
*******************************************************************************/
void DMAInit(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    NVIC_InitTypeDef NVIC_InitStruct;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);
    DMA_DeInit(DMA2_Channel1);
    //DMA transfer peripheral address
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32) & (TOUCHPAD->ADDATA);
    //DMA transfer memory address
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADCValue;
    //DMA transfer direction from peripheral to memory
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    //DMA cache size
    DMA_InitStructure.DMA_BufferSize = 1034;
    //After receiving the data, the peripheral address is forbidden to move backward
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    //After receiving the data, the memory address is shifted backward
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    //Define the peripheral data width to 16 bits
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    //Define the memory data width to 16 bits
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    //Cycle conversion mode
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    //DMA priority is high
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA2_Channel1, &DMA_InitStructure);
    DMA_Cmd(DMA2_Channel1, ENABLE);

    //DMA interrupt initialization
    DMA_ITConfig(DMA2_Channel1, DMA_IT_TC, ENABLE);
		
    NVIC_InitStruct.NVIC_IRQChannel = DMA2_Channel1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;  //次优先级0
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
		
}

/*******************************************************************************
* @name   : DMA1_Channel1_IRQHandler
* @brief  : When DMA send data, set ADCflag, clear the interrupt flag, stop the conversion
* @param  : None
* @retval : void
*******************************************************************************/
void DMA2_Channel1_IRQHandler(void)
{
		TOUCHPAD->ADCR &= 0xFFFFFEFF;//关DMA传输
    //Clear interrupt flag
    DMA_ClearITPendingBit(DMA2_IT_TC1);//清中断
    ADCflag = 1;
}

