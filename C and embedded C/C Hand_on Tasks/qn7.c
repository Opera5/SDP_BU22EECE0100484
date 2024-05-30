#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to convert MAC address string to a 48-bit binary pattern
int convertMACAddress(const char *macStr, uint8_t *macbin) {
    // Validate input
    if (macStr == NULL || macbin == NULL) {
        return -1;
    }

    // Initialize all bytes to zero
    memset(macbin, 0, 6);

    // Scan the MAC address string and convert to binary
    int result = sscanf(macStr, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
                        &macbin[0], &macbin[1], &macbin[2],
                        &macbin[3], &macbin[4], &macbin[5]);

    // Ensure that exactly 6 bytes were read
    return (result == 6) ? 0 : -1;
}

int main() {
    const char *macStr = "00:1A:2B:3C:4D:5E"; // Example MAC address
    uint8_t macbin[6];

    // Convert MAC address string to binary
    if (convertMACAddress(macStr, macbin) == 0) {
        // Print the 48-bit binary pattern as hexadecimal bytes
        printf("MAC Address in binary pattern: ");
        for (int i = 0; i < 6; i++) {
            printf("%02X", macbin[i]);
            if (i < 5) {
                printf(":");
            }
        }
        printf("\n");
    } else {
        printf("Invalid MAC address format.\n");
    }

    return 0;
}
