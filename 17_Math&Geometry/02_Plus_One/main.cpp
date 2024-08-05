#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;
    std::vector<int> digits1 = {1, 2, 3, 4};
    std::vector<int> result1 = sol.plusOne(digits1);
    std::cout << "Result: ";
    for (int digit : result1) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    std::vector<int> digits2 = {9, 9, 9};
    std::vector<int> result2 = sol.plusOne(digits2);
    std::cout << "Result: ";
    for (int digit : result2) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}
