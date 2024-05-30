#include <stdio.h>

// Function to clear the 6th and 19th bits of a 32-bit unsigned integer
unsigned int clearBit(unsigned int num) {
    // Masks for 6th  and 19th bits
    const unsigned int mask6 = ~(1 << 5);    // ~(1 shifted left by 5 positions)
    const unsigned int mask19 = ~(1 << 18);  // ~(1 shifted left by 18 positions)
    
    // Clear the 6th and 19th bits
    num &= mask6;
    num &= mask19;
    
    return num;
}

int main() {

    printf("Enter a 16-bit unsigned integer: ");
    unsigned int num = scanf("%u",&num); // Example number, initially all bits are 1 (0xFFFFFFFF)
    
    printf("given number: 0x%04X\n", num);
    
    num = clearBit(num);
    
    printf("Manipulated number: 0x%04X\n", num);
    
    return 0;
}
