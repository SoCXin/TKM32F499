#include "YS65F804U.h"
#include "TouchLib.h"
#include "YS65F804Touch.h"
#include "Uart.h"
#include "User.h"
#include "Initialize.h"
#include "Typedef.h"

#ifdef UART_EN
u16 Cap_value[TOUCH_NUM];  //打开UART功能时，如果空间不足可以屏蔽该数组
#endif	

void main(void)
{
	INTS = 0X00;
	CLR_WDT();

	SET_HIRC(IRCF_8M);  //设置系统时钟频率 8M 

	InitPort();         // IO口初始化
	
	InitTouch();        // 触摸通道初始化
	
	CheckLowClk(TOUCH_SCAN_TIME);  //时钟校准扫描周期

	#ifdef TIMER0_EN
	InitTimer0();       //Timer0初始化
	#endif

	#ifdef TIMER1_EN
	InitTimer1();       //Timer1初始化
	#endif	

	#ifdef PWM_EN
	InitPWM();          //PWM初始化
	#endif 

	#ifdef UART_EN
	InitUart();         //串口调试初始化，占用TIME0资源，若使能T0，相关TIMER0功能会失效
	#endif	

	while(1)
	{
		CLR_WDT();

		if(CSIF)   // CSIF 标志位根据触摸扫描周期TOUCH_SCAN_TIME置起，假设设置10ms，则CSIF每10MS置起一次
		{
			CSIF = 0;		
						
			TouchPro();  //触摸算法函数，执行后产生触摸结果TouchResult，bit3-bit0代表CCH3-CCH0的触摸状态，1有触摸，0没有触摸
			User();  	 //用户程序
			
			//串口打印数据
			#ifdef UART_EN
			u8 i;

			for (i = 0; i < TOUCH_NUM; i++)
			{
				if(Cap[i] >= CapTh[i])
				{
					Cap_value[i] = Cap[i] - CapTh[i];      //差值 = 触摸电容值 - 环境值，相当于手指触摸时的变化量
				}
				else
				{
					Cap_value[i] = 0;
				}
			}

		//	UartSendCap(&Cap, 0);  //通过Uart发送当前电容值
		//	UartSendCap(&CapTh, 0);  //通过Uart发送当前环境电容值
			UartSendCap(&Cap_value, 0);  //通过Uart手指触摸时的变化量
		//	UartSendUcharByHex(&CapDifLib,1);  //通过Uart发送已设置触摸灵敏度
			UartSendUcharByHex(&TouchResult,1);  //通过Uart发送触摸结果值
			UartString("\n");
			#endif
		}
		//User();  	 //若对时间计数有精准要求时，请将用户程序移到CSIF标志位外执行
	}
}

void interrupt Isr(void)
{
	#ifdef TIMER0_EN
	if(TIF)
	{
		TIF = 0;	    //100us
	}
	#endif

	#ifdef TIMER1_EN
	if(T1IF)
	{
		T1IF = 0;
		TMR1L = 0x9c;    //100us
		TMR1H = 0xff;
	}
	#endif	
}
