#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create a hash map to store the difference of the target and each element
        std::unordered_map<int, int> numMap;
        
        // Traverse the vector to find the required pair
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of the two numbers
                return {numMap[complement], i};
            }
            
            // Add the current element and its index to the map
            numMap[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector (though the problem guarantees a solution exists)
        return {};
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> nums1 = {3, 4, 5, 6};
    int target1 = 7;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Example 1: [" << result1[0] << ", " << result1[1] << "]" << std::endl; // Output: [0, 1]
    
    // Example 2
    std::vector<int> nums2 = {4, 5, 6};
    int target2 = 10;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Example 2: [" << result2[0] << ", " << result2[1] << "]" << std::endl; // Output: [0, 2]
    
    // Example 3
    std::vector<int> nums3 = {5, 5};
    int target3 = 10;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Example 3: [" << result3[0] << ", " << result3[1] << "]" << std::endl; // Output: [0, 1]

    return 0;
}
