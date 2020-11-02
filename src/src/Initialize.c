#include "YS65F804U.h"
#include "Initialize.h"
#include "Uart.h"


/*
����:void InitPort(void)
����: ��IO��ʼ��
*/
void InitPort(void)
{	
	PORTA = 0X00;

	//B5-B0:�ֱ��ӦPA5-PA0, 0����ڣ�1����� 
	CPIOA = 0X00;

	//B5-B0:�ֱ��ӦPA5-PA0��������λ, 1ʹ������ 
	PAPHR = 0X00;

	//B5-B4,B2-B0:�ֱ��ӦPA5-PA4,PA2-PA0��������λ��1ʹ������
	WPDA  = 0X00;

	PORTA = 0X00;

	//B5-B0:�ֱ��ӦPA5-PA0��ƽ�仯�жϿ���λ��1ʹ�ܶ�Ӧ���ŵ�ƽ�仯�ж�
	PAINTR = 0X00;
	
	//���Ź�����
	WDTCON = 0x15; //1:32768   1/(31000/32768) == 1.05s
}

/*
���ڳ�ʼ��
*/
#ifdef UART_EN
void InitUart(void)
{
	TIS = 0;
	GIE = 0;
	//�رղ����жϣ����ڴ�ӡ�������ж�

	SET_UART_OUTPUT();  	//����Uart�����
	UART_H();
	
	OPT_REG = 0x00;  		// 2��Ƶ
	TMR0 = 256 - 52;		// 19200������
	T0EN = 1;
}
#endif	

/*
T0��ʼ��
*/
#ifdef TIMER0_EN
void InitTimer0(void)
{
	// T0 8λ�Զ����ض�ʱ��
	// B4: 1ʹ��T0; B3 :1 ��Ƶ����WDT��0��Ƶ����T0;
	// B2-B0: 0-7,��Ƶ����T0���ζ�Ӧ��Ƶ��2-256,��Ƶ����WDT���ζ�Ӧ��Ƶ��1-128

	OPT_REG = 0x00;     //8M/4/2 = 1us
	TMR0 = 256 - 100;	//100us
	T0EN = 1;
	TIS  = 1;
	GIE  = 1;	
}
#endif

/*
T1��ʼ��
*/
#ifdef TIMER1_EN
void InitTimer1(void)
{	
	
	// T1 16λ�������ض�ʱ��
	T1IE = 0;
	
	// B5B4:T1ʱ��Դ��Ƶ��ѡ��00,01,10,11���ζ�Ӧ1,2,4,8
	// B0: 1ʹ��T1
	T1STA = 0x30;

	// TMR1L T1��������8λ
	TMR1L = 0x9c;

	// TMR1H T1��������8λ,������������0XFFFF->0X0000�������������־
	TMR1H = 0xff;
	
	T1IF = 0;
	TMR1ON = 1;
	T1IE = 1;
	GIE  = 1;
}
#endif

/*
PWM��ʼ��
*/
#ifdef PWM_EN
void InitPWM(void)
{	

	//  B3:1 PWM1��PA4���; 0 PWM1��PA2���
	//  B2:1 PWM0��PA3���; 0 PWM0��PA1���
	//  B1:1 ����PWM1�����B0: 1����PWM0���
	PWMCON = 0X00;

	T1STA  = 0x30; //1:8

	// PWM���ڼĴ�����8λ
	T1PRLL = 99;  //(T1PRH,T1PRLL + 1)*TOSC*T1��Ƶֵ  (99+1)* 8 * 1/8

	// PWM���ڼĴ�����2λ
	T1PRLH = 0;

	// PWM0 ռ�ձ����ؼĴ�����8λ
	PRL0L = 0x00;

	// PWM0 ռ�ձȱȽϼĴ�����8λ
	PWM0L = 0X00;

	// B3B2:PWM0�ȽϼĴ�����2λ��B1B0: PWM0���ؼĴ�����2λ
	EPR0 = 0X00;
	
	// PWM1 ռ�ձ����ؼĴ�����8λ
	PRL1L = 0X00;

	// PWM1 ռ�ձȱȽϼĴ�����8λ
	PWM1L = 0X00;

	// B3B2:PWM1�ȽϼĴ�����2λ��B1B0: PWM1���ؼĴ�����2λ
	EPR1 = 0X00;


	CPIOA &= ~0X04;		// ���ö�ӦPWM��Ϊ�����

	// B5B4:T1ʱ��Դ��Ƶ��ѡ��00,01,10,11���ζ�Ӧ1,2,4,8
	// B0: 1ʹ��T1

	//*/
	PWM0EN = 1;
	PWM1EN = 1;
	TMR1ON = 1;
	//*/
}
#endif

	

