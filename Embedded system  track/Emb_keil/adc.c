#include <reg51.h>
sbit rs=P2^0;
//sbit rw=P2^1;
sbit e=P2^2;

sbit ALE = P2^4;
 sbit OE = P2^5;
 sbit SC = P2^1;
 sbit EOC = P2^7; 
 
//Declaring the input selection pin
 sbit ADDR_A = P2^0;
 sbit ADDR_B = P2^1;
 sbit ADDR_C = P2^2;

void delay(unsigned int);
void WriteCommandToLCD(unsigned char ch);
void WriteDataToLCD(unsigned char ch);
void WriteStringToLCD(unsigned char ch[]);
void main(void)
{
	//	unsigned char ch[]="ES TRAINING";
	unsigned char ch1[]="GITAM UNIVERSITY, BANGALORE";
	unsigned int j,k;
	unsigned int MyData = 20;
		 
//LCD Intialization
	WriteCommandToLCD(0x38); //2 lines and 5×7 matrix
	WriteCommandToLCD(0x01); //Clear display screen
	WriteCommandToLCD(0x0E); //Display on, cursor off
	WriteCommandToLCD(0x80); //Force cursor to the beginning ( 1st line)
	WriteCommandToLCD(0x06); //Increment cursor (shift cursor to right)

//Sending Data to LCD
	WriteStringToLCD("ES TRAINING"); //Sending the string to LCD
	WriteCommandToLCD(0xc0); //Force cursor to the beginning ( 2nd line)
	for(j=0;ch1[j]!='\0';j++)
		{
			WriteDataToLCD(ch1[j]); // Sending one character to LCD
		}
	for(k=0;k<30;k++)
		{
			WriteCommandToLCD(0x1c);// shift entire dispaly right
		}
	while(1)
		{
			WriteCommandToLCD(0x01); //Clear display screen
			WriteCommandToLCD(0x80); //Force cursor to the beginning ( 1st line)
			WriteStringToLCD("CLASS STRENGTH");//Sending String to LCD
			WriteCommandToLCD(0xc0); //Force cursor to the beginning ( 2nd line)
			WriteDataToLCD((MyData / 10) + 48);//seperating the first digit of MyData
			WriteDataToLCD((MyData % 10) + 48);//seperating the first digit of MyData
			WriteStringToLCD(" STUDENTS"); //Sending String to LCD
		}
	//}
}
void delay(unsigned int t)////Function for setting 1ms delay
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);
}

void WriteCommandToLCD(unsigned char ch) //Function for sending Command
{
	e=1; 
	rs=0;
	rw=0;
	P1= ch & 0xF0;
	e=0;
	delay(20);
}
void WriteDataToLCD(unsigned char ch) //Function for sending Data
{
	e=1;
	rs=1;
	rw=0;
	P1=ch & 0xF0;
	e=0;
	delay(20);
}
void WriteStringToLCD(unsigned char ch[]) //Function for sending string
{
	int i;
	 for(i=0;ch[i]!='\0';i++)
	{
	    WriteDataToLCD(ch[i]);
	}  
}