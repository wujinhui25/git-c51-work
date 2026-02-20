#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

unsigned char KeyNum;

unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
//	for(i=1;i<5;i++)
//	{
//		P1=0xFF;
//		switch(i)
//		{
//			case 1:P1_7=0;break;
//			case 2:P1_6=0;break;
//			case 3:P1_5=0;break;
//			case 4:P1_4=0;break;
//		}
//		cnt=(i-1)*4;
//		if(P1_3==0){Delayms(10);while(P1_3==0);Delayms(10);KeyNumber=1+cnt;}
//		if(P1_2==0){Delayms(10);while(P1_2==0);Delayms(10);KeyNumber=2+cnt;}
//		if(P1_1==0){Delayms(10);while(P1_1==0);Delayms(10);KeyNumber=3+cnt;}
//		if(P1_0==0){Delayms(10);while(P1_0==0);Delayms(10);KeyNumber=4+cnt;}
//		
//	}
	P1=0xFF;
	P1_7=0;
	if(P1_3==0){Delayms(10);while(P1_3==0);Delayms(10);KeyNumber=1;}
	if(P1_2==0){Delayms(10);while(P1_2==0);Delayms(10);KeyNumber=2;}
	if(P1_1==0){Delayms(10);while(P1_1==0);Delayms(10);KeyNumber=3;}
	if(P1_0==0){Delayms(10);while(P1_0==0);Delayms(10);KeyNumber=4;}
	
	P1=0xFF;
	P1_6=0;
	if(P1_3==0){Delayms(10);while(P1_3==0);Delayms(10);KeyNumber=5;}
	if(P1_2==0){Delayms(10);while(P1_2==0);Delayms(10);KeyNumber=6;}
	if(P1_1==0){Delayms(10);while(P1_1==0);Delayms(10);KeyNumber=7;}
	if(P1_0==0){Delayms(10);while(P1_0==0);Delayms(10);KeyNumber=8;}
	
	P1=0xFF;
	P1_5=0;
	if(P1_3==0){Delayms(10);while(P1_3==0);Delayms(10);KeyNumber=9;}
	if(P1_2==0){Delayms(10);while(P1_2==0);Delayms(10);KeyNumber=10;}
	if(P1_1==0){Delayms(10);while(P1_1==0);Delayms(10);KeyNumber=11;}
	if(P1_0==0){Delayms(10);while(P1_0==0);Delayms(10);KeyNumber=12;}
	
	P1=0xFF;
	P1_4=0;
	if(P1_3==0){Delayms(10);while(P1_3==0);Delayms(10);KeyNumber=13;}
	if(P1_2==0){Delayms(10);while(P1_2==0);Delayms(10);KeyNumber=14;}
	if(P1_1==0){Delayms(10);while(P1_1==0);Delayms(10);KeyNumber=15;}
	if(P1_0==0){Delayms(10);while(P1_0==0);Delayms(10);KeyNumber=16;}

	return KeyNumber;
	
}

//LCD_Init();
//void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
//void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
//void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
//void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
//void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
//void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);


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
			}
			count++;
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
		if(KeyNum==12)
		{
			password/=10;
			count--;
			LCD_ShowNum(2,1,password,5);
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
		
	while(1)
	{
		LCD_ShowNum(2,1,password,5);
		Passeord ();
	}
}