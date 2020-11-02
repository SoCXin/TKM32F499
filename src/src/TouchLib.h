#include "Typedef.h"
#ifndef _TOUCHLIB_H_
#define _TOUCHLIB_H_

/*OSCCON*/

#define IRCF_31K		0X00
#define IRCF_250K		0X10
#define IRCF_500K		0X20
#define IRCF_1M			0X30
#define IRCF_2M			0X40
#define IRCF_4M			0X50		/*default*/
#define IRCF_8M			0X60
#define IRCF_16M		0X70

#define SET_HIRC(val)		do {OSCCON = val;} while (0)


/* CSANA0 */

#define CSANA0_BIAS_3_5UA		0X00		// BIAS 电流35UA
#define CSANA0_BIAS_3_75UA		0X10
#define CSANA0_BIAS_4UA			0X20		// default
#define CSANA0_BIAS_4_25UA		0X30
#define CSANA0_BIAS_4_5UA		0X40
#define CSANA0_BIAS_5UA			0X50
#define CSANA0_BIAS_5_5UA		0X60
#define CSANA0_BIAS_6UA			0X70

#define CSANA0_CMP_6UA			0X00		// 触摸内部比较器消耗电路6UA
#define CSANA0_CMP_12UA			0X04		// default
#define CSANA0_CMP_18UA			0X08
#define CSANA0_CMP_24UA			0X0C

#define CSANA0_CMP_0_65V		0X00		// 触摸内部比较高电平0.65V
#define CSANA0_CMP_1_3V			0X01
#define CSANA0_CMP_1_9V			0X02
#define CSANA0_CMP_2_55V		0X03		// defalut

/* CSANA1 */

#define CSANA1_TIME_0_75US		0X00		// 触摸放电时间
#define CSANA1_TIME_1US			0X08		// default
#define CSANA1_TIME_1_25US		0X10
#define CSANA1_TIME_1_5US		0X18

#define CSANA1_CAP_256PF		0X00		// 触摸量程选择,256pf
#define CSANA1_CAP_128PF		0X01
#define CSANA1_CAP_96PF			0X02
#define CSANA1_CAP_64PF			0X03		//default
#define CSANA1_CAP_56PF			0X04
#define CSANA1_CAP_48PF			0X05
#define CSANA1_CAP_40PF			0X06
#define CSANA1_CAP_32PF			0X07

//#define CSANA1_VAL				(CSANA1_TIME_1_5US | CSANA1_CAP_32PF)

/* CSCTL */

#define CSCTL_EN				0X80		// 1 使能触摸模块
#define CSCTL_CSRAM				0X40		// 1 CSRAM 有MCU控制，0 CSRAM有触摸控制
#define CSCTL_CSIE				0X20		// 0 禁止触摸中断; 1 允许触中断
#define CSCTL_CSBUSY			0X10		// 1 触摸正在扫描，0 触摸空闲
#define CSCTL_INTTS				0X08		// 1有触摸产生中断

#define CSCTL_CNT_1				0x00		// 一次触摸扫描，单个通道扫描的次数1
#define CSCTL_CNT_2				0x01
#define CSCTL_CNT_4				0x02
#define CSCTL_CNT_8				0x03
#define CSCTL_CNT_16			0x04
#define CSCTL_CNT_32			0x05
#define CSCTL_CNT_64			0x06
#define CSCTL_CNT_128			0x07

/*THCTL*/
#define THFIB_EN			0X00     //门限抽取间隔帧数		
#define THFIB_DISEN		0X80	

#define THGAP_3			0X00     //门限抽取间隔帧数		
#define THGAP_7			0X20	
#define THGAP_15			0X40
#define THGAP_31			0X60

#define THMOD_2			0X00     //门限累加次数	
#define THMOD_4			0X04	
#define THMOD_8			0X08
#define THMOD_16			0X0B
#define THMOD_32			0X10     
#define THMOD_64			0X14	
#define THMOD_128			0X18
#define THMOD_256			0X1B

#define THDS_16			0X00     //触摸按键释放后门限更新累加所需要间隔的帧数
#define THDS_32			0X01	
#define TTHDS_64			0X02
#define THDS_128			0X03


#define CCH0				0X01
#define CCH1				0X02
#define CCH2				0X04
#define CCH3				0X08
#define CCH2_PA5		0X84

#define TOUCH_EN()				do {CSCTL |= CSCTL_EN;} while (0)
#define TOUCH_DIS()				do {CSCTL &= ~CSCTL_EN;} while (0)

#define MCU_RAM()				do {CSCTL |= CSCTL_CSRAM;} while (0)
#define TOUCH_RAM()				do {CSCTL &= ~CSCTL_CSRAM;} while (0)

#define CH0_CAP					0X1A8  //电容值RAM
#define CH0_TH					0X1A0

#define CH0_CAPH				0X1A8
#define CH0_CAPL				0X1A9
#define CH1_CAPH				0X1AA
#define CH1_CAPL				0X1AB
#define CH2_CAPH				0X1AC
#define CH2_CAPL				0X1AD
#define CH3_CAPH				0X1AE
#define CH3_CAPL				0X1AF

#define CH0_THH					0X1A0
#define CH0_THL					0X1A1
#define CH1_THH					0X1A2
#define CH1_THL					0X1A3
#define CH2_THH					0X1A4
#define CH2_THL					0X1A5
#define CH3_THH					0X1A6
#define CH3_THL					0X1A7


#define CH0_TH_SUMH			0X1B8
#define CH0_TH_SUMM			0X1B9
#define CH1_TH_SUMH			0X1BA
#define CH1_TH_SUMM			0X1BB
#define CH2_TH_SUMH			0X1BC
#define CH2_TH_SUMM			0X1BD
#define CH3_TH_SUMH			0X1BE
#define CH3_TH_SUMM			0X1BF

#define CH0_DIFH				0X1B0
#define CH0_DIFL					0X1B1
#define CH1_DIFH				0X1B2
#define CH1_DIFL					0X1B3
#define CH2_DIFH				0X1B4
#define CH2_DIFL					0X1B5
#define CH3_DIFH				0X1B6
#define CH3_DIFL					0X1B7

#define SET_TOUCH_CHANNEL(val)		do {CHSELL =((val >> 0) & 0xff);} while (0)

#define SET_TOUCH_SCAN_TIME(val)	do {CSTMRL = (((val -0) >> 1) & 0xff);} while (0)


extern u16 Cap[], CapTh[], CapThSum[];
extern  u8 CapDif[];

extern u8 CapThCnt, CapThSampleCnt;
extern u8 Chatter;
extern u8 Filtration;
extern u8 TouchNum;
extern u8 TouchChannle;
extern u8 TouchResult;

//extern bit BFaceUpData;

extern u8 TouchUpDebounce[];
extern u8 TouchDebounce[];
extern u16 ResetTime;
extern u8 CapDifLib[];
extern bit BSteady;

extern void InitTouch(void);
extern void InitTouchDeviceRam(void);
extern void GetCap(u16 *ptr);
extern void Sleep_Pro(void);
extern void TouchPro(void);
extern void TouchScan(void);

#define REG_W(addr,value)			do { *((u8 *)addr) = value; } while (0)

//extern u8 ScanN, ScanS;

extern u8 CheckLowClk(u8 inDat);

#endif

