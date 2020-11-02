#ifndef	__YS65F804_H__
#define	__YS65F804_H__

// 2018-4-24 11:25:59 BY:ÎâÆ½ÉúÐÞ¸Ä

volatile unsigned char		IAR						@	0x0000;
volatile unsigned char		TMR0					@	0x0001;
volatile unsigned char		PCL						@	0x0002;

volatile unsigned char		STATUS				@	0x0003;
//        STATUS  Bits
volatile bit		C					@	 ((unsigned)&STATUS*8)+0;
volatile bit		HC				@	 ((unsigned)&STATUS*8)+1;
volatile bit		Z					@	 ((unsigned)&STATUS*8)+2;
volatile bit		PF				@	 ((unsigned)&STATUS*8)+3;
volatile bit		TF				@	 ((unsigned)&STATUS*8)+4;
volatile bit		RP0				@	 ((unsigned)&STATUS*8)+5;
volatile bit		RP1				@	 ((unsigned)&STATUS*8)+6;
volatile bit		IRP				@	 ((unsigned)&STATUS*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	C				: 1;
	unsigned	HC			: 1;
	unsigned	Z				: 1;
	unsigned	PF			: 1;
	unsigned	TF			: 1;
	unsigned	RP0			: 1;
	unsigned	RP1			: 1;
	unsigned	IRP			: 1;
	};
} _STATUSbits @ 0x0003;
#endif
volatile unsigned char		MSR					@	0x0004;
volatile unsigned char		PORTA				@	0x0005;
//        PORTA  Bits
volatile bit		PA0				@	 ((unsigned)&PORTA*8)+0;
volatile bit		PA1				@	 ((unsigned)&PORTA*8)+1;
volatile bit		PA2				@	 ((unsigned)&PORTA*8)+2;
volatile bit		PA3				@	 ((unsigned)&PORTA*8)+3;
volatile bit		PA4				@	 ((unsigned)&PORTA*8)+4;
volatile bit		PA5				@	 ((unsigned)&PORTA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PA0			: 1;
	unsigned	PA1			: 1;
	unsigned	PA2			: 1;
	unsigned	PA3			: 1;
	unsigned	PA4			: 1;
	unsigned	PA5			: 1;
	};
} _PORTAbits @ 0x0005;
#endif
volatile unsigned char		PCLATH			@	0x000A;

volatile unsigned char		INTS				@	0x000B;
//        INTS  Bits
volatile bit		PAIF			@	 ((unsigned)&INTS*8)+0;
volatile bit		T1IF			@	 ((unsigned)&INTS*8)+1;
volatile bit		TIF				@	 ((unsigned)&INTS*8)+2;
volatile bit		PAIE			@	 ((unsigned)&INTS*8)+3;
volatile bit		T1IE			@	 ((unsigned)&INTS*8)+4;
volatile bit		TIS				@	 ((unsigned)&INTS*8)+5;
volatile bit		CSIF			@	 ((unsigned)&INTS*8)+6;
volatile bit		GIE				@	 ((unsigned)&INTS*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PAIF		: 1;
	unsigned	T1IF		: 1;
	unsigned	TIF			: 1;
	unsigned	PAIE		: 1;
	unsigned	T1IE		: 1;
	unsigned	TIS			: 1;
	unsigned	CSIF		: 1;
	unsigned	GIE			: 1;
	};
} _INTSbits @ 0x000B;
#endif
volatile unsigned char		TMR1L				@	0x000E;
volatile unsigned char		TMR1H				@	0x000F;
volatile unsigned char		T1STA				@	0x0010;
//        T1STA  Bits
volatile bit		TMR1ON		@	 ((unsigned)&T1STA*8)+0;
volatile bit		T1CKPS0		@	 ((unsigned)&T1STA*8)+4;
volatile bit		T1CKPS1		@	 ((unsigned)&T1STA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	TMR1ON			: 1;
	unsigned 	RESERVE			: 3;
	unsigned	T1CKPS0			: 1;
	unsigned	T1CKPS1			: 1;
	};
} _T1STAbits @ 0x0010;
#endif
volatile unsigned char		WDTCMTH			@	0x0016;

volatile unsigned char		WDTCMTL			@	0x0017;
volatile unsigned char		WDTCON			@	0x0018;
//        WDTCON  Bits
volatile bit		SWDTEN		@	 ((unsigned)&WDTCON*8)+0;
volatile bit		WDTPS0		@	 ((unsigned)&WDTCON*8)+1;
volatile bit		WDTPS1		@	 ((unsigned)&WDTCON*8)+2;
volatile bit		WDTPS2		@	 ((unsigned)&WDTCON*8)+3;
volatile bit		WDTPS3		@	 ((unsigned)&WDTCON*8)+4;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	SWDTEN			: 1;
	unsigned	WDTPS0			: 1;
	unsigned	WDTPS1			: 1;
	unsigned	WDTPS2			: 1;
	unsigned	WDTPS3			: 1;
	};
} _WDTCONbits @ 0x0018;
#endif

volatile unsigned char		PWMCON			@	0x001A;
//        PWMT0EB  Bits
volatile bit		PWM0EN		@	 ((unsigned)&PWMCON*8)+0;
volatile bit		PWM1EN		@	 ((unsigned)&PWMCON*8)+1;
volatile bit		PWM0SEL		@	 ((unsigned)&PWMCON*8)+2;
volatile bit		PWM1SEL		@	 ((unsigned)&PWMCON*8)+3;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PWM0EN			: 1;
	unsigned	PWM1EN			: 1;
	unsigned	PWM0SEL			: 1;
	unsigned	PWM1SEL			: 1;
	};
} _PWMCONbits @ 0x001A;
#endif
volatile unsigned char		OPT_REG			@	0x0081;
//        OPT_REG  Bits
volatile bit		PS0				@	 ((unsigned)&OPT_REG*8)+0;
volatile bit		PS1				@	 ((unsigned)&OPT_REG*8)+1;
volatile bit		PS2				@	 ((unsigned)&OPT_REG*8)+2;
volatile bit		PSC				@	 ((unsigned)&OPT_REG*8)+3;
volatile bit		T0EN			@	 ((unsigned)&OPT_REG*8)+4;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PS0			: 1;
	unsigned	PS1			: 1;
	unsigned	PS2			: 1;
	unsigned	PSC			: 1;
	unsigned	T0EN		: 1;
	};
} _OPT_REGbits @ 0x0081;
#endif
volatile unsigned char		CPIOA				@	0x0085;
//        CPIOA  Bits
volatile bit		CPIOA0		@	 ((unsigned)&CPIOA*8)+0;
volatile bit		CPIOA1		@	 ((unsigned)&CPIOA*8)+1;
volatile bit		CPIOA2		@	 ((unsigned)&CPIOA*8)+2;
volatile bit		CPIOA3		@	 ((unsigned)&CPIOA*8)+3;
volatile bit		CPIOA4		@	 ((unsigned)&CPIOA*8)+4;
volatile bit		CPIOA5		@	 ((unsigned)&CPIOA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CPIOA0			: 1;
	unsigned	CPIOA1			: 1;
	unsigned	CPIOA2			: 1;
	unsigned	CPIOA3			: 1;
	unsigned	CPIOA4			: 1;
	unsigned	CPIOA5			: 1;
	};
} _CPIOAbits @ 0x0085;
#endif
volatile unsigned char		PSTA				@	0x008E;
//        PSTA  Bits
volatile bit		BOR				@	 ((unsigned)&PSTA*8)+0;
volatile bit		POR				@	 ((unsigned)&PSTA*8)+1;
volatile bit		IER				@	 ((unsigned)&PSTA*8)+2;
volatile bit		MCLR			@	 ((unsigned)&PSTA*8)+3;
volatile bit		SBOREN		@	 ((unsigned)&PSTA*8)+4;
volatile bit		LVDEN			@	 ((unsigned)&PSTA*8)+5;
volatile bit		LVDF			@	 ((unsigned)&PSTA*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	BOR			: 1;
	unsigned	POR			: 1;
	unsigned	IER			: 1;
	unsigned	MCLR		: 1;
	unsigned	SBOREN	: 1;
	unsigned	LVDEN		: 1;
	unsigned	LVDF		: 1;
	};
} _PSTAbits @ 0x008E;
#endif
volatile unsigned char		OSCCON			@	0x008F;
//        OSCCON  Bits
volatile bit		LTS				@	 ((unsigned)&OSCCON*8)+1;
volatile bit		HTS				@	 ((unsigned)&OSCCON*8)+2;
volatile bit		IRCF0			@	 ((unsigned)&OSCCON*8)+4;
volatile bit		IRCF1			@	 ((unsigned)&OSCCON*8)+5;
volatile bit		IRCF2			@	 ((unsigned)&OSCCON*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned  RESERVE0  : 1;
	unsigned	LTS				: 1;
	unsigned	HTS				: 1;
	unsigned  RESERVE1  : 1;
	unsigned	IRCF0			: 1;
	unsigned	IRCF1			: 1;
	unsigned	IRCF2			: 1;
	};
} _OSCCONbits @ 0x008F;
#endif
volatile unsigned char		PAPHR				@	0x0095;
//        PAPHR  Bits
volatile bit		PAPHR0		@	 ((unsigned)&PAPHR*8)+0;
volatile bit		PAPHR1		@	 ((unsigned)&PAPHR*8)+1;
volatile bit		PAPHR2		@	 ((unsigned)&PAPHR*8)+2;
volatile bit		PAPHR3		@	 ((unsigned)&PAPHR*8)+3;
volatile bit		PAPHR4		@	 ((unsigned)&PAPHR*8)+4;
volatile bit		PAPHR5		@	 ((unsigned)&PAPHR*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PAPHR0			: 1;
	unsigned	PAPHR1			: 1;
	unsigned	PAPHR2			: 1;
	unsigned	PAPHR3			: 1;
	unsigned	PAPHR4			: 1;
	unsigned	PAPHR5			: 1;
	};
} _PAPHRbits @ 0x0095;
#endif
volatile unsigned char		PAINTR			@	0x0096;
//        PAINTR  Bits
volatile bit		PAINTR0		@	 ((unsigned)&PAINTR*8)+0;
volatile bit		PAINTR1		@	 ((unsigned)&PAINTR*8)+1;
volatile bit		PAINTR2		@	 ((unsigned)&PAINTR*8)+2;
volatile bit		PAINTR3		@	 ((unsigned)&PAINTR*8)+3;
volatile bit		PAINTR4		@	 ((unsigned)&PAINTR*8)+4;
volatile bit		PAINTR5		@	 ((unsigned)&PAINTR*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PAINTR0			: 1;
	unsigned	PAINTR1			: 1;
	unsigned	PAINTR2			: 1;
	unsigned	PAINTR3			: 1;
	unsigned	PAINTR4			: 1;
	unsigned	PAINTR5			: 1;
	};
} _PAINTRbits @ 0x0096;
#endif
volatile unsigned char		WPDA				@	0x0097;
//        WPDA  Bits
volatile bit		PDA0			@	 ((unsigned)&WPDA*8)+0;
volatile bit		PDA1			@	 ((unsigned)&WPDA*8)+1;
volatile bit		PDA2			@	 ((unsigned)&WPDA*8)+2;
volatile bit		PDA4			@	 ((unsigned)&WPDA*8)+4;
volatile bit		PDA5			@	 ((unsigned)&WPDA*8)+5;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	PDA0			: 1;
	unsigned	PDA1			: 1;
	unsigned	PDA2			: 1;
	unsigned	RESERVE		: 1;
	unsigned	PDA4			: 1;
	unsigned	PDA5			: 1;
	};
} _WPDAbits @ 0x0097;
#endif
volatile unsigned char		PRL0L				@	0x0112;
volatile unsigned char		PRL1L				@	0x0113;

volatile unsigned char		T1PRLL			@	0x0117;



volatile unsigned char		CSCTL				@	0x0190;
//        CSCTL  Bits
volatile bit		CSACU0		@	 ((unsigned)&CSCTL*8)+0;
volatile bit		CSACU1		@	 ((unsigned)&CSCTL*8)+1;
volatile bit		CSACU2		@	 ((unsigned)&CSCTL*8)+2;
volatile bit		CSINTS		@	 ((unsigned)&CSCTL*8)+3;
volatile bit		CSBUSY		@	 ((unsigned)&CSCTL*8)+4;
volatile bit		CSIE			@	 ((unsigned)&CSCTL*8)+5;
volatile bit		RAMEN			@	 ((unsigned)&CSCTL*8)+6;
volatile bit		CSEN			@	 ((unsigned)&CSCTL*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CSACU0			: 1;
	unsigned	CSACU1			: 1;
	unsigned	CSACU2			: 1;
	unsigned	CSINTS			: 1;
	unsigned	CSBUSY			: 1;
	unsigned	CSIE				: 1;
	unsigned	RAMEN				: 1;
	unsigned	CSEN				: 1;
	};
} _CSCTLbits @ 0x0190;
#endif
volatile unsigned char		THCTL				@	0x0191;
//        THCTL  Bits
volatile bit		THDS0			@	 ((unsigned)&THCTL*8)+0;
volatile bit		THDS1			@	 ((unsigned)&THCTL*8)+1;
volatile bit		THMOD0		@	 ((unsigned)&THCTL*8)+2;
volatile bit		THMOD1		@	 ((unsigned)&THCTL*8)+3;
volatile bit		THMOD2		@	 ((unsigned)&THCTL*8)+4;
volatile bit		THGAP0		@	 ((unsigned)&THCTL*8)+5;
volatile bit		THGAP1		@	 ((unsigned)&THCTL*8)+6;
volatile bit		THFIB			@	 ((unsigned)&THCTL*8)+7;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	THDS0				: 1;
	unsigned	THDS1				: 1;
	unsigned	THMOD0			: 1;
	unsigned	THMOD1			: 1;
	unsigned	THMOD2			: 1;
	unsigned	THGAP0			: 1;
	unsigned	THGAP1			: 1;
	unsigned	THFIB				: 1;
	};
} _THCTLbits @ 0x0191;
#endif
volatile unsigned char		PWM0L				@	0x0192;
volatile unsigned char		PWM1L				@	0x0193;
volatile unsigned char		CHRLTL			@	0x0195;

volatile unsigned char		CHSELL			@	0x0197;
volatile unsigned char		EPR0				@	0x0198;
volatile unsigned char		EPR1				@	0x0199;
volatile unsigned char		T1PRLH			@	0x019A;

volatile unsigned char		CSTMRL			@	0x019C;

volatile unsigned char		CSANA0			@	0x019E;
//        CSANA0  Bits
volatile bit		VTSEL0		@	 ((unsigned)&CSANA0*8)+0;
volatile bit		VTSEL1		@	 ((unsigned)&CSANA0*8)+1;
volatile bit		CMPTRM0		@	 ((unsigned)&CSANA0*8)+2;
volatile bit		CMPTRM1		@	 ((unsigned)&CSANA0*8)+3;
volatile bit		BSTRM0		@	 ((unsigned)&CSANA0*8)+4;
volatile bit		BSTRM1		@	 ((unsigned)&CSANA0*8)+5;
volatile bit		BSTRM2		@	 ((unsigned)&CSANA0*8)+6;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	VTSEL0			: 1;
	unsigned	VTSEL1			: 1;
	unsigned	CMPTRM0			: 1;
	unsigned	CMPTRM1			: 1;
	unsigned	BSTRM0			: 1;
	unsigned	BSTRM1			: 1;
	unsigned	BSTRM2			: 1;
	};
} _CSANA0bits @ 0x019E;
#endif
volatile unsigned char		CSANA1			@	0x019F;
//        CSANA1  Bits
volatile bit		CTTRM0		@	 ((unsigned)&CSANA1*8)+0;
volatile bit		CTTRM1		@	 ((unsigned)&CSANA1*8)+1;
volatile bit		CTTRM2		@	 ((unsigned)&CSANA1*8)+2;
volatile bit		DTTRM0		@	 ((unsigned)&CSANA1*8)+3;
volatile bit		DTTRM1		@	 ((unsigned)&CSANA1*8)+4;
#ifndef _LIB_BUILD 
volatile union
{
	struct
	{
	unsigned	CTTRM0			: 1;
	unsigned	CTTRM1			: 1;
	unsigned	CTTRM2			: 1;
	unsigned	DTTRM0			: 1;
	unsigned	DTTRM1			: 1;
	};
} _CSANA1bits @ 0x019F;

#endif

#define CLR_WDT() do {asm("clrwdt");} while (0)
#define SLEEP() 	do {asm("sleep");  asm("NOP"); asm("NOP"); ;} while (0)//asm("clrwdt");asm("clrwdt")

#endif // #ifndef __YS65F804_H__
