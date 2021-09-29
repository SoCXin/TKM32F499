#include "key.h"

void KEY_Init(void) //IO???
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);			//使能按键IO的时钟
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

u8 KEY_Scan(u8 mode)
{
    static u8 key_up=1;     //按键松开标志
    if(mode==1)key_up=1;    //支持连按
    if(key_up && WK_UP == 1)
    {
      key_up=0;
     return KEY1_PRES;
          
    }else  if(WK_UP == 0)key_up=1;
    return 0;   //无按键按下
}

