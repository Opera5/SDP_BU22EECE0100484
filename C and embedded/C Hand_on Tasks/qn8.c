#include <stdio.h>
#include <stdint.h>

// Function to convert a 48-bit binary MAC address to a string
void convertToMACString(uint8_t *macBinary, char *macStr) {
    // Format the MAC address as a string
    sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X",
            macBinary[0], macBinary[1], macBinary[2],
            macBinary[3], macBinary[4], macBinary[5]);
}

int main() {
    // Example MAC address in binary form
    uint8_t macBinary[6] = {0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
    char macStr[18]; // Buffer to hold the MAC address string (17 characters + null terminator)

    // Convert the binary MAC address to a string
    convertToMACString(macBinary, macStr);

    // Print the MAC address string
    printf("MAC Address: %s\n", macStr);

    return 0;
}
