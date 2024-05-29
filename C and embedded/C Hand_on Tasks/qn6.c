#include <stdio.h>
#include <stdint.h>

// Function to unpack the IP address components from a 32-bit unsigned integer
void IPunpacked(uint32_t packedIP, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d) {
    *a = (packedIP >> 24) & 0xFF;
    *b = (packedIP >> 16) & 0xFF;
    *c = (packedIP >> 8) & 0xFF;
    *d = packedIP & 0xFF;
}

int main() {
    uint32_t packedIP = 0xC0A8A10B; // Example packed IP address (192.168.1.1)
    
    uint8_t a, b, c, d;
    IPunpacked(packedIP, &a, &b, &c, &d);

    // Print the unpacked IP address in "a.b.c.d" format
    printf("Packed IP Address: %u\n", packedIP);
    printf("Unpacked IP Address: %u.%u.%u.%u\n", a, b, c, d);

    return 0;
}
