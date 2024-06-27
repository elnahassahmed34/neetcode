#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> nums1 = {1, 2, 3, 3};
    bool result1 = solution.hasDuplicate(nums1);
    std::cout << "Example 1: " << std::boolalpha << result1 << std::endl; // Output: true
    
    // Example 2
    std::vector<int> nums2 = {1, 2, 3, 4};
    bool result2 = solution.hasDuplicate(nums2);
    std::cout << "Example 2: " << std::boolalpha << result2 << std::endl; // Output: false
    
    return 0;
}
