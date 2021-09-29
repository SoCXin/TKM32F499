#ifndef __KEY_H
#define	__KEY_H

#include "HAL_conf.h"

#define WK_UP      GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)  //WKUP°´¼üPA0
#define KEY0_PRES 	0
#define KEY1_PRES	  1

void KEY_Init(void);
uint8_t KEY_Down(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
u8 KEY_Scan(u8 mode);
#endif /* __KEY_H */

