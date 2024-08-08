#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;

    int m = matrixSize;
    int n = matrixColSize[0];
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

int main() {
    int matrix[3][4] = {
        {1, 2, 4, 8},
        {10, 11, 12, 13},
        {14, 20, 30, 40}
    };
    int* matrixPtrs[3] = {matrix[0], matrix[1], matrix[2]};
    int matrixColSize[3] = {4, 4, 4};

    int target = 10;
    bool result = searchMatrix(matrixPtrs, 3, matrixColSize, target);
    printf("Target %d %s in the matrix.\n", target, result ? "found" : "not found");

    target = 15;
    result = searchMatrix(matrixPtrs, 3, matrixColSize, target);
    printf("Target %d %s in the matrix.\n", target, result ? "found" : "not found");

    return 0;
}
