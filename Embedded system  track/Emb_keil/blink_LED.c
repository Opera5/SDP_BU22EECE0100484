#include <reg51.h>
sbit sw1 = P2^1;
sbit sw2 = P2^2;

unsigned int b;
void delay(unsigned int);
void main (void)
	{

			sw1 = 0;
		  sw2 = 0;

		
		while(1)
			{
				//P1 = 0x00;
				/*
					if (sw1 == 0 && sw2 == 0 )
						{
								P1 = 0x00;
						
							}
					else if (sw1 == 1 && sw2 == 0)
						{
									P1 = 0xF0;
							delay(500);
									P1 = 0x00;
							delay(500);
							
							}
					else if (sw1 == 0 && sw2 == 1)
						{	
						P1 = 0x0F;
							delay(500);
						P1 = 0x00;
							delay(500);
					}		
					else if (sw1 == 1 && sw2 == 1)
						{
							
								P1 = 0xFF;
								delay(500);
								P1 = 0x00;
								delay(500);
					
					}*/
				

		 
  for(b = 0; b < 8; b++)
  {    
  const unsigned int mask = 1 << b;
       unsigned short num = 0x00;
       num |= mask;
       
      // PORTB = mask;
		P1 = num;
       delay(500);
    }
		
		}
}
	
void delay(unsigned int t)
{
	unsigned int i, j;
	for (i = 0, i < t ; i++;)
	for (j = 0; j <1275 ; j++);
		
}