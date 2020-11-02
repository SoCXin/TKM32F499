#include "YS65F804U.h"
#include "Uart.h"
#include "Typedef.h"

#ifdef UART_EN

const u8 NumTable[] = {'0','1','2','3','4','5','6','7','8','9',
						'a','b','c','d','e','f','\r','\n',};

void UartDelay(void)
{
	while (!TIF) asm("clrwdt");

	TIF = 0;
}



void UartSend(u8 dat)
{
	u8 send;
	u8 i;

	send = dat;
	
	UartDelay();
	UartDelay();

	UART_L();

	UartDelay();

	for (i = 0; i < 8; i++)
	{
		if (0x01 == (send & 0x01))
		{
			UART_H();
		}
		else
		{
			UART_L();
		}

		send >>= 1;
		UartDelay();
	}

//	UART_L();
//	UartDelay();

	UART_H();
}




void UartString(const char *s)
{
	while (*s)
	{
		UartSend(*s++);
	}
}




void UartSendUintByDecimal(u16 *p, u8 num)
{
	u16 tmp16;
	u8 i;

	u8 UintH, UintHL, UintM, UintL, UintLL;
	
	if (0 != num)
	{
		for (i = 0; i < num; i++)
		{
			tmp16 = *p++;
			
			UintH = tmp16 / 10000;
			UintHL = (tmp16 % 10000) / 1000;
			UintM = (tmp16 % 1000) / 100;
			UintL = (tmp16 % 100) / 10;
			UintLL = tmp16 % 10;

			UartString(" ");
			
			if (0 == UintH)
			{
				UartString(" ");
			}
			else
			{
				UartSend(NumTable[UintH]);
			}

			if ((0 == UintHL) && (0 == UintH))
			{
				UartString(" ");
			}
			else
			{
				UartSend(NumTable[UintHL]);
			}

			if ((0 == UintM) && (0 == UintHL) && (0 == UintH))
			{
				UartString(" ");
			}
			else
			{
				UartSend(NumTable[UintM]);
			}

			if ((0 == UintL) && (0 == UintM) && (0 == UintHL) && (0 == UintH))
			{
				UartString(" ");
			}
			else
			{
				UartSend(NumTable[UintL]);
			}

			UartSend(NumTable[UintLL]);
		}
		
	}
}




void UartSendUcharByHex(u8 *p, u8 num)
{
	u8 tmp8;
	u8 i;
	
	if (0 != num)
	{
		for (i = 0; i < num; i++)
		{
			tmp8 = *p++;

			UartString(" ");
			
			UartSend(NumTable[(tmp8>>4)&0X0F]);
			UartSend(NumTable[(tmp8>>0)&0X0F]);
				
		}
	}
}



void UartSendCap(u16 *p, u8 mode)
{
	u16 tmp16;
	u8 i;
	u16 *ptr = p;
	
	u8 UintH, UintHL, UintM, UintL, UintLL;
	
	for (i = 0; i < TOUCH_NUM; i++)
	{
		tmp16 = *ptr++;

		//if (0X0000 != (TOUCH_CHANNEL & (1 << i)))
		//{
			if (0 == mode)
			{
				UintH = tmp16 / 10000;
				UintHL = (tmp16 % 10000) / 1000;
				UintM = (tmp16 % 1000) / 100;
				UintL = (tmp16 % 100) / 10;
				UintLL = tmp16 % 10;

				/*
				由于我们的触摸模块是12位的电容值，所以每次发送
				数据之前没有发送空格隔开两个数据
				*/
				
				if (0 == UintH)
				{
					UartString(" ");
				}
				else
				{
					UartSend(NumTable[UintH]);
				}

				if ((0 == UintHL) && (0 == UintH))
				{
					UartString(" ");
				}
				else
				{
					UartSend(NumTable[UintHL]);
				}

				if ((0 == UintM) && (0 == UintHL) && (0 == UintH))
				{
					UartString(" ");
				}
				else
				{
					UartSend(NumTable[UintM]);
				}

				if ((0 == UintL) && (0 == UintM) && (0 == UintHL) && (0 == UintH))
				{
					UartString(" ");
				}
				else
				{
					UartSend(NumTable[UintL]);
				}
				
				UartSend(NumTable[UintLL]);
				
			}
			else
			{
				UartString(" ");
				UartSend(NumTable[(tmp16>>12)&0X0F]);
				UartSend(NumTable[(tmp16>>8)&0X0F]);
				UartSend(NumTable[(tmp16>>4)&0X0F]);
				UartSend(NumTable[(tmp16>>0)&0X0F]);
			}
		//}
	}
}

#endif

