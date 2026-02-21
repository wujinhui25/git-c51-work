#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKeypro.h"

unsigned char KeyNum;
unsigned long password;

void Passeord ()
{
	static unsigned char count;
	KeyNum=MatrixKey();
	if(KeyNum)
	{
		if(KeyNum<11)
		{
			if(count<5)
			{
				password*=10;
				password+=KeyNum%10;
				count++;
			}
			
			LCD_ShowNum(2,1,password,5);
		}
		if(KeyNum==11)
		{
			
			if(password==20266)
			{
				LCD_ShowString(1,13,"OK!");
			}else	{
					LCD_ShowString(1,13,"ERR!");
					Delayms(1500);
					LCD_ShowString(1,13,"    ");
					password=0;
					count=0;
					LCD_ShowNum(2,1,password,5);
						}
		}
		if(password!=20266)
		{
			if(KeyNum==12)
			{	
				if(count>0)
				{
					password/=10;
					count--;
					LCD_ShowNum(2,1,password,5);
				}
			}
		}
		if(KeyNum==13)
		{
			LCD_ShowString(1,13,"    ");
			password=0;
			count=0;
			LCD_ShowNum(2,1,password,5);
		}
	}
}

void main ()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowNum(2,1,password,5);
	while(1)
	{
		Passeord ();
	}
}