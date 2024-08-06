#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int xor_all = 0;
        int n = nums.size();

        // XOR all indices from 0 to n
        for (int i = 0; i <= n; ++i) {
            xor_all ^= i;
        }

        // XOR all numbers in the array
        for (int num : nums) {
            xor_all ^= num;
        }

        // The result will be the missing number
        return xor_all;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {0, 2};

    std::cout << "Missing number in nums1: " << sol.missingNumber(nums1) << std::endl; // Output: 0
    std::cout << "Missing number in nums2: " << sol.missingNumber(nums2) << std::endl; // Output: 1

    return 0;
}
