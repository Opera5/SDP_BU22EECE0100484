sbit e = P2^2;
void delay(unsignedint)
void WriteCommandToLCD(unsigned char ch);
void WriteDataToLCD(unsigned char ch);



//unsigned char ch[] = "ES TRAINING";
unsigned char ch1[] =  "GITAM UNIVERSITY, BANGALORE";
unsigned int j,k;
unsigned int MyData = 20;

//LCD Initialization
	WriteCommandToLCD(0x38);  //2 lines and 5x7 matrix
	WriteCommandToLCD(0x38); 
WriteCommandToLCD(0x38); 
WriteCommandToLCD(0x38); 
void delay(unsigned int t)
{
	unsigned int i, j;
	for (i = 0, i < t ; i++;)
	for (j = 0; j <1275 ; j++);
		
}