#include <stdio.h>

// Function to find the maximum area
int maxArea(int* heights, int heightsSize) {
    int left = 0;                // Left pointer
    int right = heightsSize - 1; // Right pointer
    int maxArea = 0;             // To store the maximum area found

    while (left < right) {
        // Calculate the area with the current left and right bars
        int height = heights[left] < heights[right] ? heights[left] : heights[right];
        int width = right - left;
        int currentArea = height * width;

        // Update maxArea if a larger area is found
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }

        // Move the pointer pointing to the shorter bar inward
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

// Example usage
int main() {
    int heights1[] = {1,7,2,5,4,7,3,6};
    int size1 = sizeof(heights1) / sizeof(heights1[0]);
    printf("Max Water Container Area: %d\n", maxArea(heights1, size1)); // Output: 36

    int heights2[] = {2,2,2};
    int size2 = sizeof(heights2) / sizeof(heights2[0]);
    printf("Max Water Container Area: %d\n", maxArea(heights2, size2)); // Output: 4

    return 0;
}
