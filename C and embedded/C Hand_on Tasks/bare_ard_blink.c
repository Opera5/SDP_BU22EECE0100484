#define LED_PIN 13

void delay(unsigned int t)
{
	unsigned int i, j;
	for (i = 0, i < t ; i++;)
	for (j = 0; j <1275 ; j++);
		
}

void setup() {
    // Set the LED pin as an output
    DDRB |= (1 << DDB5); // DDRB is the Data Direction Register for Port B. DDB5 corresponds to pin 13.
}

void loop() {
    // Turn the LED on
    PORTB |= (1 << PORTB5); // PORTB is the output register for Port B. PORTB5 corresponds to pin 13.
    delay(500); // Wait for 500 milliseconds
    
    // Turn the LED off
    PORTB &= ~(1 << PORTB5); // Clear the bit to turn the LED off
    delay(500); // Wait for 500 milliseconds
}
