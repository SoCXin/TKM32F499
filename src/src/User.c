#include "YS65F804U.h"
#include "TouchLib.h"
#include "Typedef.h"

u16 sleepCnt = 0x0000;

///**********************************
//
//��������User
//
//�������ܣ��û�����
//
//***********************************
void User(void)
{
	
	// �û������Լ��ĳ��򣬵ȴ������ȶ���ִ��Sleep();
	// ִ��˯�ߺ���򽫲������У�ֱ���ٴ��д�������˳��ִ�У��˳�Sleep()������

	if(0x01 == TouchResult)//��CCH0�д������
	{
	//	LED = 1; ����
	}
	else//�����ɿ���0x00 == TouchResult
	{
	//	LED = 0; ����
	}

	if (0x00 != TouchResult)
	{
		sleepCnt = 0x0000;
	}

	if (++sleepCnt >= 1000)
	{
		sleepCnt = 0x0000;
		
		Sleep_Pro();  //˯�ߴ�����
	}
}
