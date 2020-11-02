#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

//#define TIMER0_EN       //打开宏定义TIME0_EN ，可以配置TIMER0功能
//#define TIMER1_EN		 //打开宏定义TIME1_EN ，可以配置TIMER1功能
//#define PWM_EN		 //打开宏定义PWM_EN ，可以配置PWM功能

extern void InitPort(void);
extern void InitTimer0(void);
extern void InitTimer1(void);
extern void InitPWM(void);
extern void InitUart(void);

#endif

