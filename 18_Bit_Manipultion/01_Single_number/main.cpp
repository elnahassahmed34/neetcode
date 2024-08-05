#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3, 2, 3};
    cout << "Single number in [3, 2, 3] is: " << sol.singleNumber(nums1) << endl; // Output: 2
    
    vector<int> nums2 = {7, 6, 6, 7, 8};
    cout << "Single number in [7, 6, 6, 7, 8] is: " << sol.singleNumber(nums2) << endl; // Output: 8
    
    vector<int> nums3 = {1, 1, 2, 2, 3};
    cout << "Single number in [1, 1, 2, 2, 3] is: " << sol.singleNumber(nums3) << endl; // Output: 3
    
    return 0;
}
