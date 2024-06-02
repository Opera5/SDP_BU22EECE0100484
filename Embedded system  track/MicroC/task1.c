

 // LCD CONNECTIONS
sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;

sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;
// End LCD module connections

// Tact switches and Relay ports
sbit Relay at RA3_bit;
sbit SS_Select at RC2_bit;    // Start Stop Timer Select
sbit Unit_Button at RC0_bit;  // Set unit min
sbit Ten_Button at RC1_bit;   // Set ten min


// Messages
char Message1[]="00-99 min Timer";
char Message2[]="Device ON";
char Message3[]="Device OFF";
char Message4[]="Set Time:    min";
char Message5[]="Time Left:   min";
unsigned short i, j, unit=0, ten=0, ON_OFF=0, index=0, clear, time, out;
char *digit = "00";
// 300ms Delay
void Delay_300(){
 Delay_ms(300);
}

void Display_Digits(){
 digit[1]=unit+48;
 digit[0]=ten+48;
 Lcd_Out(2,11,digit);
}


void start_timer(unsigned short MinVal){
 unsigned short temp1, temp2;
 Relay = 1;
 ON_OFF = 1;
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1,1,Message2);
 Lcd_Out(2,1,Message5);
 OPTION_REG = 0x80 ;
 INTCON = 0x90;
 for (i=0; i<MinVal; i++){
  temp1 = (MinVal-i)%10 ;
  temp2 = (MinVal-i)/10 ;
  Lcd_Chr(2, 12, temp2+48);
  Lcd_Chr(2, 13, temp1+48);
  j=1;
  do {
  Delay_ms(1000);
  j++;
  } while(((j<=60) && (Clear ==0)));
  if (Clear) {
   Relay = 0;
   Delay_ms(500);
   Lcd_Out(1,1,Message3);
   INTCON = 0x00;
   goto stop;
   }
 }
 stop:
 Relay = 0;
 ON_OFF = 0;
 unit = 0;
 ten = 0;
 clear = 1;
}

void interrupt(void){
  if (INTCON.INTF == 1)   // Check if INTF flag is set
   {
    Clear = 1;
    INTCON.INTF = 0;       // Clear interrupt flag before exiting ISR
   }
  }

void main() {
  CMCON  |= 7;                       // Disable Comparators
  TRISC.F0 = 0xFF;
  TRISC.F1 = 0xFF;
  TRISC.F2 = 0xFF;
  TRISA = 0b11110000;
  Relay = 0;

  Lcd_Init();                        // Initialize LCD
 start:
  clear = 0;
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,1,Message1);
  Lcd_Out(2,1,Message4);
  Display_Digits()  ;
 do {

     if(!Unit_Button){
     Delay_300();
     unit ++;
     if(unit==10) unit=0;
     Display_Digits();
    } // If !Unit_Button

    if(!Ten_Button){
     Delay_300();
     ten ++;
     if(ten==10) ten=0;
     Display_Digits();
    } // If !Ten_Button

    if(!SS_Select){
     Delay_300();
     time = ten*10+unit ;
     if(time > 0) start_timer(time);
    } // If !SS_Select

    if(clear){
     goto start;
    }
   } while(1);
}