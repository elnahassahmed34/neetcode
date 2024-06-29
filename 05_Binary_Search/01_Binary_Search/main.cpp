#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        return -1; // Target not found
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {-1, 0, 2, 4, 6, 8};
    int target1 = 4;
    cout << "Output: " << solution.search(nums1, target1) << endl; // Output: 3

    vector<int> nums2 = {-1, 0, 2, 4, 6, 8};
    int target2 = 3;
    cout << "Output: " << solution.search(nums2, target2) << endl; // Output: -1

    return 0;
}
