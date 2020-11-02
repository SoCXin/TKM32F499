#include "YS65F804U.h"
#include "TouchLib.h"
#include "Typedef.h"

u16 sleepCnt = 0x0000;

///**********************************
//
//函数名：User
//
//函数功能：用户程序
//
//***********************************
void User(void)
{
	
	// 用户根据自己的程序，等待触摸稳定后执行Sleep();
	// 执行睡眠后程序将不在运行，直到再次有触摸，会顺序执行，退出Sleep()；函数

	if(0x01 == TouchResult)//若CCH0有触摸结果
	{
	//	LED = 1; 灯亮
	}
	else//触摸松开，0x00 == TouchResult
	{
	//	LED = 0; 灯灭
	}

	if (0x00 != TouchResult)
	{
		sleepCnt = 0x0000;
	}

	if (++sleepCnt >= 1000)
	{
		sleepCnt = 0x0000;
		
		Sleep_Pro();  //睡眠处理函数
	}
}
