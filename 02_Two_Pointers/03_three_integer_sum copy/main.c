#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find and print all unique triplets that sum to zero
void threeSum(int* nums, int numsSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 2; ++i) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);
                // Skip duplicate values for the second element
                while (left < right && nums[left] == nums[left + 1]) ++left;
                // Skip duplicate values for the third element
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
}

int main() {
    // Example usage
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    threeSum(nums, numsSize);
    
    return 0;
}
