#include <stdio.h>

// Function to count the number of set bits in an integer
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // Increment count if the least significant bit is 1
        n >>= 1;         // Right shift n by 1 to check the next bit
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    int setBits = countSetBits(num);
    printf("Number of set bits in %u is %d\n", num, setBits);

    return 0;
}
