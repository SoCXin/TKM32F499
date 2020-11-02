
#include "Typedef.h"
#include "YS65F804Touch.h"


#ifndef _UART_H_
#define _UART_H_

//#define UART_EN		// 打开宏定义UART_EN，配置串口功能，请注意TOUCH_SCAN_TIME参数需增加10ms 。


#define SET_UART_OUTPUT()			do {CPIOA &= ~0X20;} while (0)		/* 配置UART 为输出口*/ 
#define UART_H()					do {PORTA |=  0X20;} while (0)		 //PA5,根据实际情况修改输出口
#define UART_L()					do {PORTA &= ~0X20;} while (0)


extern void UartSend(u8 dat);

extern void UartString(const char *s);

extern void UartSendUintByDecimal(u16 *p, u8 num);

extern void UartSendUcharByHex(u8 *p, u8 num);

extern void UartSendCap(u16 *p, u8 mode);

#endif

