#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;   // To store all subsets
        vector<int> currentSubset;    // To store the current subset being formed
        generateSubsets(nums, 0, currentSubset, result);
        return result;
    }
    
private:
    // Helper function to generate all subsets
    void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(currentSubset);
        
        // Explore further subsets by including elements one by one
        for (int i = index; i < nums.size(); ++i) {
            // Include nums[i] in the current subset
            currentSubset.push_back(nums[i]);
            
            // Move to the next element with the updated subset
            generateSubsets(nums, i + 1, currentSubset, result);
            
            // Backtrack by removing the last added element
            currentSubset.pop_back();
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> subsets1 = solution.subsets(nums1);
    
    cout << "Subsets of [1, 2, 3]:" << endl;
    for (const auto& subset : subsets1) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    // Test case 2
    vector<int> nums2 = {7};
    vector<vector<int>> subsets2 = solution.subsets(nums2);
    
    cout << "Subsets of [7]:" << endl;
    for (const auto& subset : subsets2) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
