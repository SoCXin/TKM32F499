#include "YS65F804U.h"
#include "Initialize.h"
#include "Uart.h"


/*
函数:void InitPort(void)
功能: 各IO初始化
*/
void InitPort(void)
{	
	PORTA = 0X00;

	//B5-B0:分别对应PA5-PA0, 0输出口，1输入口 
	CPIOA = 0X00;

	//B5-B0:分别对应PA5-PA0上拉控制位, 1使能上拉 
	PAPHR = 0X00;

	//B5-B4,B2-B0:分别对应PA5-PA4,PA2-PA0下拉控制位，1使能下拉
	WPDA  = 0X00;

	PORTA = 0X00;

	//B5-B0:分别对应PA5-PA0电平变化中断控制位，1使能对应引脚电平变化中断
	PAINTR = 0X00;
	
	//看门狗设置
	WDTCON = 0x15; //1:32768   1/(31000/32768) == 1.05s
}

/*
串口初始化
*/
#ifdef UART_EN
void InitUart(void)
{
	TIS = 0;
	GIE = 0;
	//关闭部分中断，串口打印不允许开中断

	SET_UART_OUTPUT();  	//设置Uart输出口
	UART_H();
	
	OPT_REG = 0x00;  		// 2分频
	TMR0 = 256 - 52;		// 19200波特率
	T0EN = 1;
}
#endif	

/*
T0初始化
*/
#ifdef TIMER0_EN
void InitTimer0(void)
{
	// T0 8位自动加载定时器
	// B4: 1使能T0; B3 :1 分频器给WDT，0分频器给T0;
	// B2-B0: 0-7,分频器给T0依次对应分频比2-256,分频器给WDT依次对应分频比1-128

	OPT_REG = 0x00;     //8M/4/2 = 1us
	TMR0 = 256 - 100;	//100us
	T0EN = 1;
	TIS  = 1;
	GIE  = 1;	
}
#endif

/*
T1初始化
*/
#ifdef TIMER1_EN
void InitTimer1(void)
{	
	
	// T1 16位不可重载定时器
	T1IE = 0;
	
	// B5B4:T1时钟源分频比选择00,01,10,11依次对应1,2,4,8
	// B0: 1使能T1
	T1STA = 0x30;

	// TMR1L T1计数器低8位
	TMR1L = 0x9c;

	// TMR1H T1计数器高8位,计数器计数到0XFFFF->0X0000溢出会产生溢出标志
	TMR1H = 0xff;
	
	T1IF = 0;
	TMR1ON = 1;
	T1IE = 1;
	GIE  = 1;
}
#endif

/*
PWM初始化
*/
#ifdef PWM_EN
void InitPWM(void)
{	

	//  B3:1 PWM1有PA4输出; 0 PWM1有PA2输出
	//  B2:1 PWM0有PA3输出; 0 PWM0有PA1输出
	//  B1:1 允许PWM1输出；B0: 1允许PWM0输出
	PWMCON = 0X00;

	T1STA  = 0x30; //1:8

	// PWM周期寄存器低8位
	T1PRLL = 99;  //(T1PRH,T1PRLL + 1)*TOSC*T1分频值  (99+1)* 8 * 1/8

	// PWM周期寄存器高2位
	T1PRLH = 0;

	// PWM0 占空比重载寄存器低8位
	PRL0L = 0x00;

	// PWM0 占空比比较寄存器低8位
	PWM0L = 0X00;

	// B3B2:PWM0比较寄存器高2位；B1B0: PWM0重载寄存器高2位
	EPR0 = 0X00;
	
	// PWM1 占空比重载寄存器低8位
	PRL1L = 0X00;

	// PWM1 占空比比较寄存器低8位
	PWM1L = 0X00;

	// B3B2:PWM1比较寄存器高2位；B1B0: PWM1重载寄存器高2位
	EPR1 = 0X00;


	CPIOA &= ~0X04;		// 设置对应PWM口为输出口

	// B5B4:T1时钟源分频比选择00,01,10,11依次对应1,2,4,8
	// B0: 1使能T1

	//*/
	PWM0EN = 1;
	PWM1EN = 1;
	TMR1ON = 1;
	//*/
}
#endif

	

