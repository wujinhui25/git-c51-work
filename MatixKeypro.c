#include <REGX52.H>
#include "MatrixKeypro.h"
#include "Delay.h"

unsigned char MatrixKey()
{
	unsigned char cnt,i,KeyNumber=0;
	
	for(i=1;i<5;i++)
	{
		P1=0xFF;
		switch(i)
		{
			case 1:P1_7=0;break;
			case 2:P1_6=0;break;
			case 3:P1_5=0;break;
			case 4:P1_4=0;break;
		}
		cnt=(i-1)*4;
		if(P1_3==0){Delayms(10);while(P1_3==0);Delayms(10);KeyNumber=1+cnt;}
		if(P1_2==0){Delayms(10);while(P1_2==0);Delayms(10);KeyNumber=2+cnt;}
		if(P1_1==0){Delayms(10);while(P1_1==0);Delayms(10);KeyNumber=3+cnt;}
		if(P1_0==0){Delayms(10);while(P1_0==0);Delayms(10);KeyNumber=4+cnt;}
		
	}

	return KeyNumber;
	
}