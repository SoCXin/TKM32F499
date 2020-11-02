#include "YS65F804U.h"
#include "TouchLib.h"
#include "YS65F804Touch.h"
#include "User.h"
#include "Typedef.h"

u8 CapDif[4] = {TOUCH0_DIF, TOUCH1_DIF, TOUCH2_DIF, TOUCH3_DIF,};
u8 TouchUpDebounce[TOUCH_NUM];
u8 TouchDebounce[TOUCH_NUM];

u8 CapDifLib[TOUCH_NUM];
u16 Cap[TOUCH_NUM], CapTh[TOUCH_NUM], CapThSum[TOUCH_NUM];
u8 TouchChannle;

u8 TouchResult = 0X00;			// �������ֵ��ÿ��λ��Ӧһ������ͨ����1�д�����0û�д���

u16 ResetTime;

u8 ScanN, ScanS;

//bit bGie;

void InitTouch(void)
{
	u8 i, j, k;
	
	TouchChannle = TOUCH_CHANNEL;
	ResetTime = RESET_TOUCH_TIME;

	CPIOA |= (TOUCH_CHANNEL & 0X03);
	PAPHR |=(TOUCH_CHANNEL & 0X03);
	
	if(0x08 == (TOUCH_CHANNEL & 0x08))
	{
		CPIOA |= 0X10;
		PAPHR |= 0X10;
	}

	if(0x84 == (TOUCH_CHANNEL & 0x84))
	{
		CHSELL |= 0X80;  //CCH2ѡ��PA5
		CPIOA  |= 0X20;
		PAPHR  |= 0X20;
	}
	else if(0x04 == (TOUCH_CHANNEL & 0x04))
	{
		CHSELL &= 0X7f;  //CCH2ѡ��PA2
		CPIOA  |= 0X04;
		PAPHR  |= 0X04;
	}


	CHSELL = TOUCH_CHANNEL;
	
	SET_TOUCH_SCAN_TIME((TOUCH_SCAN_TIME));

	InitTouchDeviceRam();
	
	CSANA0 = CSANA0_VAL;     //����������
	CSANA1 = CSANA1_VAL;
	THCTL  = THCTL_VAL;
	CSCTL  = CSCTL_VAL;
	
	Chatter = SET_CHATTER;  
	Filtration = SET_FILTRATION;
	TouchNum = TOUCH_NUM;
	

	for (i = 0; i < TOUCH_NUM; i++)
	{
		CapTh[i] = 0x0FFF;
		CapThSum[i] = 0x0000;
		TouchDebounce[i] = 0;
	}

	for(i = 0, k = 0x01, j = 0; i < 4; i++)
	{
		if(k == (k & TouchChannle))
		{
			CapDifLib[j++] = CapDif[i];
		}	
		k <<= 1;
	}
	
	TouchResult = 0X00;
	CapThCnt = 0;
	CapThSampleCnt = 0;
	
}

void InitTouchDeviceRam(void)
{
	MCU_RAM();

	REG_W(CH0_THH, 0X0F);
	REG_W(CH0_THL, 0XFF);
	REG_W(CH1_THH, 0X0F);
	REG_W(CH1_THL, 0XFF);
	REG_W(CH2_THH, 0X0F);
	REG_W(CH2_THL, 0XFF);
	REG_W(CH3_THH, 0X0F);
	REG_W(CH3_THL, 0XFF);

	REG_W(CH0_TH_SUMH, 0X00);
	REG_W(CH0_TH_SUMM, 0X00);
	REG_W(CH1_TH_SUMH, 0X00);
	REG_W(CH1_TH_SUMM, 0X00);
	REG_W(CH2_TH_SUMH, 0X00);
	REG_W(CH2_TH_SUMM, 0X00);
	REG_W(CH3_TH_SUMH, 0X00);
	REG_W(CH3_TH_SUMM, 0X00);

	REG_W(CH0_DIFH, (TOUCH0_DIF >>8) & 0XFF);
	REG_W(CH0_DIFL, CapDif[0]);
	REG_W(CH1_DIFH, (TOUCH1_DIF >>8) & 0XFF);
	REG_W(CH1_DIFL, CapDif[1]);
	REG_W(CH2_DIFH, (TOUCH2_DIF >>8) & 0XFF);
	REG_W(CH2_DIFL, CapDif[2]);
	REG_W(CH3_DIFH, (TOUCH3_DIF >>8) & 0XFF);
	REG_W(CH3_DIFL, CapDif[3]);

	TOUCH_RAM();
	
}

//*******************************************************
//
//��������Sleep_Pro
//
//�������ܣ�û����ʱIC����˯��ģʽ
//
//********************************************************
//*
void Sleep_Pro(void)
{	
	u8 i;
	u8  bitBak = 0x00;

	if(GIE)
	{
		bitBak = (bitBak|0x01);
	}
	GIE = 0;

	if(PWM0EN)
	{
		bitBak = (bitBak|0x02);		
	}
	PWM0EN = 0;

	if(PWM1EN)
	{
		bitBak = (bitBak|0x04);		
	}
	PWM1EN = 0;

	if(TMR1ON)
	{
		bitBak = (bitBak|0x08);		
	}
	TMR1ON = 0;

	if(T0EN)
	{
		bitBak = (bitBak|0x10);		
	}
	T0EN = 0;

	if(TIS)
	{
		bitBak = (bitBak|0x20);	
	}
	TIS = 0;
	TIF = 0;

	//��ʹ��PWM���ܵ�����£�У׼ǰ��Ҫ�ȹر�PWM���ܺ�TIME1
	ScanN = CheckLowClk(TOUCH_SCAN_TIME);
	ScanS = CheckLowClk(TOUCH_SCAN_TIME_SLEEP);			//У׼������˯��ʱ����ɨ������

	CSCTL = CSCTL_VAL_SLEEP;

	CSIE = 1;
	CSIF = 0;
	CSINTS = 1;
	
	CLR_WDT();

	if(0x00 == CHRLTL)  //��֤CHRLTLΪ0ʱ����˯�ߣ�����CHRLTL��Ϊ0ʱ����˯�߻᲻�ϵػ���
	{
		SLEEP();
	}

	if(CSIF == 1)
	{
		CSIF = 0;
		CLR_WDT();
	}
	else
	{
		while(!TF)//TFΪ�㣬���Ź���ʱ���
		{
			SLEEP();
		}
	}

	CSIE = 0;
	CSINTS = 0;
	
	SET_TOUCH_SCAN_TIME(ScanN);	//����˯��ʱ����ɨ������
	CSCTL = CSCTL_VAL;

	GetCap((u16 *)CH0_TH);
	
	for (i = 0; i < TOUCH_NUM; i++)
	{
		CapTh[i] = Cap[i];
	}


	if (0x20 == (bitBak&0x20))
	{
		TIS = 1;
	}

	if (0x10 == (bitBak&0x10))
	{
		T0EN = 1;
	}

	if (0x08 == (bitBak&0x08))
	{
		TMR1ON = 1;
	}

	if (0x04 == (bitBak&0x04))
	{
		PWM1EN = 1;
	}

	if (0x02 == (bitBak&0x02))
	{
		PWM0EN = 1;
	}
	
	if (0x01 == (bitBak&0x01))
	{
		GIE = 1;
	}
}
//*/


//*******************************************
//
//��������u8 CheckLowClk(u8 inDat)
//
//�������ܣ���ʱ�ӽ�����ʱ��
//
//*******************************************
u8 CheckLowClk(u8 inDat)
{	
	u8  i;
	u8  bBAK = 0x00;
	u16 tmr1Cnt;
	u32 longTmp = 0;

	u8 oscconBak = (OSCCON & 0X70);

	//���ݶ�ʱ��1����	
	u8 T1STA_Bak = (T1STA  & 0X30);
	u8 TMR1L_Bak = TMR1L;
	u8 TMR1H_Bak = TMR1H;

	if (TMR1ON)
	{
		bBAK = (bBAK|0x01);
	}

	//�������жϿ���
	if (GIE)
	{
		bBAK = (bBAK|0x02);
	}
	
	SET_HIRC(IRCF_1M);

	GIE = 0;
	
	// T1 16λ�������ض�ʱ��
	// B0: 1ʹ��T1
	TMR1ON = 0;

	// B5B4:T1ʱ��Դ��Ƶ��ѡ��00,01,10,11���ζ�Ӧ1,2,4,8
	T1STA = 0x30;

	// TMR1L T1��������8λ
	TMR1L = 0X00;

	// TMR1H T1��������8λ,������������0XFFFF->0X0000�������������־
	TMR1H = 0X00;

	SET_TOUCH_SCAN_TIME(50);

	CSIF = 0;
	while (!CSIF) CLR_WDT();

	TMR1ON = 1;

	CSIF = 0;
	while (!CSIF) CLR_WDT();

	TMR1ON = 0;
	CSIF = 0;

	tmr1Cnt = TMR1H;
	tmr1Cnt <<= 8;
	tmr1Cnt |= TMR1L;

	for (i = 0; i < inDat; i++)
	{
		CLR_WDT();
		longTmp += 50000L;
	}

	longTmp >>= 3;
	
	tmr1Cnt = longTmp/tmr1Cnt;

	SET_TOUCH_SCAN_TIME(tmr1Cnt);
	
	SET_HIRC(oscconBak);

	//��ԭ��ʱ��1����
	if (0x01 == (bBAK&0x01))
	{
		TMR1ON = 1;
	}

	T1STA = T1STA_Bak;

	// TMR1L T1��������8λ
	TMR1L = TMR1L_Bak;

	// TMR1H T1��������8λ,������������0XFFFF->0X0000�������������־
	TMR1H = TMR1H_Bak;

	//��ԭ���жϿ���
	if (0x02 == (bBAK&0x02))
	{
		GIE = 1;
	}

	return tmr1Cnt;
}

