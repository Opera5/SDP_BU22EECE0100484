#include <stdio.h>

// Function to set the 5th and 12th bits of a 16-bit unsigned integer
unsigned short setBits(unsigned short num) {
    // Masks for 5th (0x10) and 12th (0x0800) bits
    const unsigned short mask5 = 1 << 4;    // 1 shifted left by 4 positions
    const unsigned short mask12 = 1 << 11;  // 1 shifted left by 11 positions
    
    // Set the 5th and 12th bits
    num |= mask5;
    num |= mask12;
    
    return num;
}

int main() {
    printf("Enter a 16-bit unsigned integer: ");
    unsigned int num = scanf("%u",&num); // Example number, initially all bits are 0
    
    printf("given number: 0x%08X\n", num);
    
    num = setBits(num);
    
    printf("Manipulated number: 0x%08X\n", num);
    
    return 0;
}
