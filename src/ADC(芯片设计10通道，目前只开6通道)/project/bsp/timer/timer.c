#include "HAL_conf.h"
#include "timer.h"
#include "stdio.h"

 
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	static int i=1;
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
		{
				if(i)
				{
					GPIO_SetBits(GPIOD, GPIO_Pin_8); //PD8����ߵ�ƽ������LED
					i=0;
				}
				else 
				{
					GPIO_ResetBits(GPIOD, GPIO_Pin_8);//PD8����͵�ƽ��Ϩ��LED
					i=1;
				}
				
		}
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
}
//ͨ�ö�ʱ��8�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��8!
void TIM8_Config(u32 psc,u32 arr)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStruct;        //�жϲ����ṹ��
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM8,ENABLE); //TIM8ʱ��ʹ��
   TIM_TimeBaseStructure.TIM_Period = arr; //��װ��ֵ        
   TIM_TimeBaseStructure.TIM_Prescaler =psc; //Ԥ��Ƶֵ
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //���������ù�
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���
   TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); //��ʼ��
        //�ж����ȼ�NVIC���� 
   TIM_ITConfig(TIM8,TIM_IT_Update,ENABLE ); //ʹ��TIM8�жϣ���������ж�
   NVIC_InitStruct.NVIC_IRQChannel = TIM8_IRQn;  //TIM6�ж�
   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;  //ռ�����ȼ�0
   NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�0
   NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
   NVIC_Init(&NVIC_InitStruct);  //��ʼ��NVIC�Ĵ���
        
   TIM_Cmd(TIM8, ENABLE);  //ʹ��TIM8 
}

void TIM8_IRQHandler(void)
{
   static int j=1;
	if (TIM_GetITStatus(TIM8, TIM_IT_Update) != RESET)  //���TIM8�����жϷ������
		{
				if(j)
				{
					GPIO_SetBits(GPIOA, GPIO_Pin_15); //PA15����ߵ�ƽ������LED
					j=0;
				}
				else 
				{
					GPIO_ResetBits(GPIOA, GPIO_Pin_15);//PA15����͵�ƽ��Ϩ��LED
					j=1;
				}
				
		}
			TIM_ClearITPendingBit(TIM8, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
}

void TIM10_Config(u16 arr,u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStruct;        //�жϲ����ṹ��
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM10,ENABLE); //TIM8ʱ��ʹ��
   TIM_TimeBaseStructure.TIM_Period = arr; //��װ��ֵ        
   TIM_TimeBaseStructure.TIM_Prescaler =psc; //Ԥ��Ƶֵ
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //���������ù�
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���
   TIM_TimeBaseInit(TIM10, &TIM_TimeBaseStructure); //��ʼ��
        //�ж����ȼ�NVIC���� 
   TIM_ITConfig(TIM10,TIM_IT_Update,ENABLE ); //ʹ��TIM10�жϣ���������ж�
   NVIC_InitStruct.NVIC_IRQChannel = TIM10_IRQn;  //TIM10�ж�
   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;  //ռ�����ȼ�0
   NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�0
   NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
   NVIC_Init(&NVIC_InitStruct);  //��ʼ��NVIC�Ĵ���
        
   TIM_Cmd(TIM10, ENABLE);  //ʹ��TIM10 
}
void TIM10_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET)  //���TIM8�����жϷ������
		{	
			printf("I am Timer 10 \n");
		}
	TIM_ClearITPendingBit(TIM10, TIM_IT_Update  );  //���TIMx�����жϱ�־
}









