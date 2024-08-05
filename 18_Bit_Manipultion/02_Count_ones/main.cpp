#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) // Check the least significant bit
                count++;
            n >>= 1; // Right shift n by 1 bit
        }
        return count;
    }
};

int main() {
    Solution sol;

    uint32_t n1 = 0b00000000000000000000000000010111;
    uint32_t n2 = 0b01111111111111111111111111111101;

    std::cout << "Number of 1 bits in " << n1 << " : " << sol.hammingWeight(n1) << std::endl;
    std::cout << "Number of 1 bits in " << n2 << " : " << sol.hammingWeight(n2) << std::endl;

    return 0;
}
