#include <stdio.h>
#include <stdint.h>

// Function to pack the IP address components into a 32-bit unsigned integer
uint32_t packIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    return ((uint32_t)a << 24) | ((uint32_t)b << 16) | ((uint32_t)c << 8) | (uint32_t)d;
}

int main() {
    // Example values for a, b, c, d
    uint8_t a = 192;
    uint8_t b = 168;
    uint8_t c = 1;
    uint8_t d = 1;

    // Pack the IP address
    uint32_t IPpacked = packIP(a, b, c, d);

    // Print the packed IP address in hexadecimal format
    printf("Packed IP Address: 0x%08X\n", IPpacked);

    // Optionally, you can print the packed IP address in decimal format
    printf("Packed IP Address (decimal): %u\n", IPpacked);

    return 0;
}
