#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; // Left pointer starting at the beginning
        int right = heights.size() - 1; // Right pointer starting at the end
        int maxArea = 0; // To store the maximum area found

        while (left < right) {
            // Calculate the current area based on the shorter height
            int height = min(heights[left], heights[right]);
            int width = right - left;
            int currentArea = height * width;

            // Update maxArea if we found a larger one
            maxArea = max(maxArea, currentArea);

            // Move the pointer that points to the shorter bar inward
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

// Example usage
int main() {
    Solution solution;
    
    vector<int> heights1 = {1,7,2,5,4,7,3,6};
    cout << "Max Water Container Area: " << solution.maxArea(heights1) << endl; // Output: 36
    
    vector<int> heights2 = {2,2,2};
    cout << "Max Water Container Area: " << solution.maxArea(heights2) << endl; // Output: 4

    return 0;
}
