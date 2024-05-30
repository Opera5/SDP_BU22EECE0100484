#include <avr/io.h>

void ADC_init() {
    // Set the reference voltage to AVcc (5V)
    ADMUX = (1 << REFS0);

    // Set the ADC prescaler to 128 for a 16MHz clock (125kHz ADC clock)
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    // Enable the ADC
    ADCSRA |= (1 << ADEN);
}

uint16_t ADC_read(uint8_t channel) {
    // Select the ADC channel (0-7) and clear the lower 4 bits of ADMUX
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // Start the ADC conversion
    ADCSRA |= (1 << ADSC);

    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC));

    // Read the ADC value from the ADC data registers
    return ADC;
}

int main() {
    // Initialize the ADC
    ADC_init();

    uint16_t adcValue;
    uint8_t adcChannel = 0; // Read from analog pin A0 (ADC0)

    while (1) {
        // Read the analog value from the specified ADC channel
        adcValue = ADC_read(adcChannel);

        // Do something with the adcValue (e.g., send it over UART, use it to control an output, etc.)
    }

    return 0;
}
