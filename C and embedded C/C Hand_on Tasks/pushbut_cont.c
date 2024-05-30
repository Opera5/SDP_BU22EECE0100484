#define LED_PIN 13    // LED connected to digital pin 13
#define BUTTON_PIN 2  // Push button connected to digital pin 2

void setup() {
    // Set LED_PIN as an output
    DDRB |= (1 << DDB5); // Port B pin 5 (pin 13 on Arduino Uno)
    
    // Set BUTTON_PIN as an input with internal pull-up resistor
    DDRD &= ~(1 << DDD2); // Port D pin 2 (pin 2 on Arduino Uno)
    PORTD |= (1 << PORTD2); // Enable pull-up resistor on Port D pin 2
}

void loop() {
    // Read the button state
    if (PIND & (1 << PIND2)) {
        // Button not pressed, turn off the LED
        PORTB &= ~(1 << PORTB5); // Clear Port B pin 5
    } else {
        // Button pressed, turn on the LED
        PORTB |= (1 << PORTB5); // Set Port B pin 5
    }
}
