#define sw1 TRISB.F0

void main()
{
      // input declaration
  TRISB.F0 = 0xFF;
  TRISB.F1 = 0xFF;
  
           // output declaration
  TRISC.F0 = 0x00;
  TRISC.F1 = 0x00;
  TRISC.F2 = 0x00;
  TRISC.F3 = 0x00;
  TRISC.F4 = 0x00;
  TRISC.F5 = 0x00;
  TRISC.F6 = 0x00;
  TRISC.F7 = 0x00;

  //switch off all output pins
  PORTB.F0 = 0x00;
  PORTB.F1 = 0x00;
  PORTB.F2 = 0x00;
  PORTB.F3 = 0x00;
  PORTB.F4 = 0x00;
  PORTB.F5 = 0x00;
  PORTB.F6 = 0x00;
  PORTB.F7 = 0x00;



 while(1)
  {
    if((PORTB.F0 == 1) && (PORTB.F1 == 1))
     {

       PORTC = 0xFF;
      Delay_ms(500);
      PORTC = 0x00;
      Delay_ms(500);
     }
  else if((PORTB.F0 == 1) && (PORTB.F1 == 0))
  {


    PORTC = 0x0F;
    Delay_ms(500);
    PORTC = 0x00;
    Delay_ms(500);
  }
  else if((PORTB.F0 == 0) && (PORTB.F1 == 1))
       {



       PORTC = 0xF0;
       Delay_ms(500);
       PORTC = 0x00;
       Delay_ms(500);

       }
       else
       {
       
      PORTC = 0x00;
      //Delay_ms(500);

       }
  }

}