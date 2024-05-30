#include <stdio.h>

// Function to flip even positioned bits of a 16-bit unsigned integer
unsigned short flipEvenBits(unsigned short num) {
    // Mask to select even positioned bits: 0xAAAA (binary 1010101010101010)
    const unsigned short evenMask = 0xAAAA;
    
    // Flip the even positioned bits using XOR
    num ^= evenMask;
    
    return num;
}

int main() {
    unsigned short number = 0x1514; // Example number
    
    printf("Given number: 0x%04X\n", number);
    
    number = flipEvenBits(number);
    
    printf("Flipped result: 0x%04X\n", number);
    
    return 0;
}
