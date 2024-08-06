#include <stdio.h>
#include <stdint.h>

// Function to reverse the bits of a 32-bit unsigned integer
uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for (int i = 0; i < 32; ++i) {
        reversed <<= 1;
        reversed |= (n & 1);
        n >>= 1;
    }
    return reversed;
}

int main() {
    uint32_t n = 21; // Example input (00000000000000000000000000010101)
    uint32_t reversed = reverseBits(n);
    
    printf("Original: %u\n", n); // 21
    printf("Reversed: %u\n", reversed); // 2818572288

    return 0;
}
