#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(nums, target, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int target, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            currentCombination.push_back(nums[i]);
            backtrack(nums, target - nums[i], i, currentCombination, result);
            currentCombination.pop_back();
        }
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<int> nums = {2, 5, 6, 9};
    int target = 9;

    vector<vector<int>> result = solution.combinationSum(nums, target);

    for (const auto& combination : result) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
