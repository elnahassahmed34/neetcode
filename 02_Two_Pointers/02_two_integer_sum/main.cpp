#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            if (current_sum == target) {
                return {left + 1, right + 1}; // Returning 1-indexed result
            } else if (current_sum < target) {
                left++; // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }

        return {}; // Just a fallback, though the problem guarantees exactly one solution
    }
};

int main() {
    Solution solution;
    std::vector<int> numbers = {1, 2, 3, 4};
    int target = 3;
    std::vector<int> result = solution.twoSum(numbers, target);
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}
