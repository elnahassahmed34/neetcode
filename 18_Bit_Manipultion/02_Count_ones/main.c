#include <stdio.h>
#include <stdint.h>

// Function to count the number of 1 bits in the binary representation of an integer
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) // Check the least significant bit
            count++;
        n >>= 1; // Right shift n by 1 bit
    }
    return count;
}

int main() {
    uint32_t n1 = 0b00000000000000000000000000010111;
    uint32_t n2 = 0b01111111111111111111111111111101;

    printf("Number of 1 bits in %u : %d\n", n1, hammingWeight(n1));
    printf("Number of 1 bits in %u : %d\n", n2, hammingWeight(n2));

    return 0;
}
