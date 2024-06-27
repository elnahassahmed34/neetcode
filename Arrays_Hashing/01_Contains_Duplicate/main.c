#include <stdio.h>
#include <stdbool.h>

// Function to check if there are duplicates in the array
bool hasDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Example 1
    int nums1[] = {1, 2, 3, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    bool result1 = hasDuplicate(nums1, size1);
    printf("Example 1: %s\n", result1 ? "true" : "false"); // Output: true
    
    // Example 2
    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    bool result2 = hasDuplicate(nums2, size2);
    printf("Example 2: %s\n", result2 ? "true" : "false"); // Output: false
    
    return 0;
}




