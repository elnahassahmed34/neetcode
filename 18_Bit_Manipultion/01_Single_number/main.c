#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums1[] = {3, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Single number in [3, 2, 3] is: %d\n", singleNumber(nums1, size1)); // Output: 2
    
    int nums2[] = {7, 6, 6, 7, 8};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Single number in [7, 6, 6, 7, 8] is: %d\n", singleNumber(nums2, size2)); // Output: 8
    
    int nums3[] = {1, 1, 2, 2, 3};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Single number in [1, 1, 2, 2, 3] is: %d\n", singleNumber(nums3, size3)); // Output: 3
    
    return 0;
}
