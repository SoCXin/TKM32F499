#include "exit.h"
#include "Key.h"
#include "HAL_conf.h"
#include "sys.h"
#include "stdio.h"
void EXIT_KEY_Init(void)
{
	 NVIC_InitTypeDef   NVIC_InitStructure;														//调用NVIC定义的结构体

   /* Configure PA0 pin as input floating */
	KEY_Init();
	
  Ex_NVIC_Config(0,0,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下升沿;2,上降沿;3，任意电平触发

  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_Init( & NVIC_InitStructure);

}

//PA1
void EXIT1_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//PA1映射到EXTI1
	Ex_NVIC_Config(0,1,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);

}

uint32_t i;
void EXTI0_IRQHandler(void)
{    

	  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
				{          
						printf("Enter EXTI0_IRQHandler \r\n");  
					
						GPIO_SetBits(GPIOD, GPIO_Pin_8); //PC8输出高电平，点亮LED
						for(i=0;i<1000000;i++);//延时 
						GPIO_ResetBits(GPIOD, GPIO_Pin_8);//PD8输出低电平，熄灭LED
						for(i=0;i<1000000;i++);//延时
					
						GPIO_SetBits(GPIOD, GPIO_Pin_8); //PC8输出高电平，点亮LED
						for(i=0;i<1000000;i++);//延时 
						GPIO_ResetBits(GPIOD, GPIO_Pin_8);//PD8输出低电平，熄灭LED
						for(i=0;i<1000000;i++);//延时
              			
				}
	    EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位 
}
void EXTI1_IRQHandler(void)
{    

	  if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
				{          
						printf("Enter EXTI1_IRQHandler \r\n");        			
				}
	    EXTI_ClearITPendingBit(EXTI_Line1); //清除LINE0上的中断标志位 
}
//======================================================================//
//PC2
void EXIT2_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	//PD7映射到EXTI7
	Ex_NVIC_Config(2,2,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);
}
void EXTI2_IRQHandler(void)
{    

	  if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
				{          
						printf("Enter EXTI2_IRQHandler \r\n");        			
				}
	    EXTI_ClearITPendingBit(EXTI_Line2); //清除LINE2上的中断标志位 
}
//PE4
void EXIT4_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	//PD7映射到EXTI7
	Ex_NVIC_Config(4,4,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);
}
void EXTI4_IRQHandler(void)
{    

	  if(EXTI_GetITStatus(EXTI_Line4)!=RESET)
				{          
						printf("Enter EXTI4_IRQHandler \r\n");        			
				}
	    EXTI_ClearITPendingBit(EXTI_Line4); //清除LINE0上的中断标志位 
}
//PD7
void EXIT7_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	//PD7映射到EXTI7
	Ex_NVIC_Config(3,7,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);

}
//PA8
void EXIT8_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//PA8映射到EXTI8
	Ex_NVIC_Config(0,8,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);

}

//EXIT5  ----  EXTI9
void EXTI9_5_IRQHandler(void)
{  
	if(EXTI_GetITStatus(EXTI_Line7)!=RESET)
		{          
				printf("Enter EXTI7_IRQHandler \r\n");							
		}
	EXTI_ClearITPendingBit(EXTI_Line7); //清除LINE8上的中断标志位  

	if(EXTI_GetITStatus(EXTI_Line8)!=RESET)
		{          
				printf("Enter EXTI8_IRQHandler \r\n");							
		}
	EXTI_ClearITPendingBit(EXTI_Line8); //清除LINE8上的中断标志位  		
  
//	if((EXTI->SWIER &(1<<8)) == 0)
//	{
//	}
//	EXTI->PR |= 1<<8;   
}







//PB12
void EXIT12_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	Ex_NVIC_Config(1,12,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);

}
//PB13
void EXIT13_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;                                                                                                                //调用NVIC定义的结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	Ex_NVIC_Config(1,13,1); //参数一：I/O口  参数二：BITx:中断线  参数三 ：TRIM:触发模式,1,下降沿;2,上升沿;3，任意电平触发

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init( & NVIC_InitStructure);

}

//EXIT12 13
void EXTI15_10_IRQHandler(void)
{    
	if(EXTI_GetITStatus(EXTI_Line12)!=RESET)
		{          
				printf("Enter EXTI12_IRQHandler \r\n");							
		}
	EXTI_ClearITPendingBit(EXTI_Line12); //清除LINE12上的中断标志位
		
		
	if(EXTI_GetITStatus(EXTI_Line13)!=RESET)
		{          
				printf("Enter EXTI13_IRQHandler \r\n");							
		}
	EXTI_ClearITPendingBit(EXTI_Line13); //清除LINE12上的中断标志位 		
}