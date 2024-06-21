#line 1 "Z:/home/jamih/Downloads/SDP/SDP_BU22EECE0100484/Embedded system  track/MicroC/ADC.c"

sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;


unsigned long int t;
char *a;
char lcd[] = "0.00 Volt";
 unsigned long int Volt, adc;
 char *display_v = "0.00";
void main()
{
TRISC.F0 = 0x00;
 TRISC.F1 = 0x00;
 ADCON0 = 0x02;
 ADCON1 = 0;
 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);

 do
 {

 Lcd_out(1,1, "Voltage:");
 t = ADC_Read(1);
 Volt = 5 * (t / 1023);
 t = t * 0.4897;
 a = t%10;
 lcd[3] = a + '0';

 t = t/10;
 a = t%10;
 lcd[2] = a + '0';

 t = t/10;
 a = t%10;
 lcd[0] = a + '0';

 Lcd_out(2,1,lcd);


 display_v[0] = (Volt /100)%10 +48;
 display_v[2] = (Volt /10)%10 +48;
 display_v[3] = Volt %10 +48;
 Lcd_Out(2,11,display_v);

 if ((int)t >= 2) {

 PORTC.F1 = 0x00;
 PORTC.F0 = 0xFF;
 }else
 {
 PORTC.F1 = 0xFF;
 PORTC.F0 = 0x00;
 }


 }while(1);
}