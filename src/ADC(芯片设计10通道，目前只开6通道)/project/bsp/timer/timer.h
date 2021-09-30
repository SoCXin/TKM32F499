#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

void NVIC_Config(void);
void TIM3_Init(u16 arr,u16 psc);
void TIM8_Config(u32 psc,u32 arr);
void TIM10_Config(u16 arr,u16 psc);
void TIM2_Mode_Config(u16 arr,u16 psc);
void Times_Pwm_Config(u16 psc,u16 arr,u16 ccr);
#endif
