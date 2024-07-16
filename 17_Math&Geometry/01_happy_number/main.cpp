#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seenNumbers;
        while (n != 1 && seenNumbers.find(n) == seenNumbers.end()) {
            seenNumbers.insert(n);
            n = sumOfSquares(n);
        }
        return n == 1;
    }

private:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    int test1 = 100;
    int test2 = 101;

    std::cout << "Is " << test1 << " a happy number? " << (solution.isHappy(test1) ? "True" : "False") << std::endl;
    std::cout << "Is " << test2 << " a happy number? " << (solution.isHappy(test2) ? "True" : "False") << std::endl;

    return 0;
}
