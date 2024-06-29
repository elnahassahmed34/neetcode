#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

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

int main() {
    int nums1[] = {-1, 0, 2, 4, 6, 8};
    int target1 = 4;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", search(nums1, size1, target1)); // Output: 3

    int nums2[] = {-1, 0, 2, 4, 6, 8};
    int target2 = 3;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", search(nums2, size2, target2)); // Output: -1

    return 0;
}
