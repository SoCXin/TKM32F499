#include "YS65F804U.h"
#include "TouchLib.h"
#include "YS65F804Touch.h"
#include "Uart.h"
#include "User.h"
#include "Initialize.h"
#include "Typedef.h"

#ifdef UART_EN
u16 Cap_value[TOUCH_NUM];  //��UART����ʱ������ռ䲻��������θ�����
#endif	

void main(void)
{
	INTS = 0X00;
	CLR_WDT();

	SET_HIRC(IRCF_8M);  //����ϵͳʱ��Ƶ�� 8M 

	InitPort();         // IO�ڳ�ʼ��
	
	InitTouch();        // ����ͨ����ʼ��
	
	CheckLowClk(TOUCH_SCAN_TIME);  //ʱ��У׼ɨ������

	#ifdef TIMER0_EN
	InitTimer0();       //Timer0��ʼ��
	#endif

	#ifdef TIMER1_EN
	InitTimer1();       //Timer1��ʼ��
	#endif	

	#ifdef PWM_EN
	InitPWM();          //PWM��ʼ��
	#endif 

	#ifdef UART_EN
	InitUart();         //���ڵ��Գ�ʼ����ռ��TIME0��Դ����ʹ��T0�����TIMER0���ܻ�ʧЧ
	#endif	

	while(1)
	{
		CLR_WDT();

		if(CSIF)   // CSIF ��־λ���ݴ���ɨ������TOUCH_SCAN_TIME���𣬼�������10ms����CSIFÿ10MS����һ��
		{
			CSIF = 0;		
						
			TouchPro();  //�����㷨������ִ�к�����������TouchResult��bit3-bit0����CCH3-CCH0�Ĵ���״̬��1�д�����0û�д���
			User();  	 //�û�����
			
			//���ڴ�ӡ����
			#ifdef UART_EN
			u8 i;

			for (i = 0; i < TOUCH_NUM; i++)
			{
				if(Cap[i] >= CapTh[i])
				{
					Cap_value[i] = Cap[i] - CapTh[i];      //��ֵ = ��������ֵ - ����ֵ���൱����ָ����ʱ�ı仯��
				}
				else
				{
					Cap_value[i] = 0;
				}
			}

		//	UartSendCap(&Cap, 0);  //ͨ��Uart���͵�ǰ����ֵ
		//	UartSendCap(&CapTh, 0);  //ͨ��Uart���͵�ǰ��������ֵ
			UartSendCap(&Cap_value, 0);  //ͨ��Uart��ָ����ʱ�ı仯��
		//	UartSendUcharByHex(&CapDifLib,1);  //ͨ��Uart���������ô���������
			UartSendUcharByHex(&TouchResult,1);  //ͨ��Uart���ʹ������ֵ
			UartString("\n");
			#endif
		}
		//User();  	 //����ʱ������о�׼Ҫ��ʱ���뽫�û������Ƶ�CSIF��־λ��ִ��
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
