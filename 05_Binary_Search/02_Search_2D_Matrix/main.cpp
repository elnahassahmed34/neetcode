#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / n][mid % n];

            if (mid_value == target) {
                return true;
            } else if (mid_value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
    int target = 10;

    bool result = sol.searchMatrix(matrix, target);
    if (result) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }

    target = 15;
    result = sol.searchMatrix(matrix, target);
    if (result) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }

    return 0;
}
