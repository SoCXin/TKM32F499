#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

//#define TIMER0_EN       //�򿪺궨��TIME0_EN ����������TIMER0����
//#define TIMER1_EN		 //�򿪺궨��TIME1_EN ����������TIMER1����
//#define PWM_EN		 //�򿪺궨��PWM_EN ����������PWM����

extern void InitPort(void);
extern void InitTimer0(void);
extern void InitTimer1(void);
extern void InitPWM(void);
extern void InitUart(void);

#endif

