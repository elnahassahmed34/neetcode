#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int xor_all = 0;
    for (int i = 0; i <= numsSize; i++) {
        xor_all ^= i;
    }

    for (int i = 0; i < numsSize; i++) {
        xor_all ^= nums[i];
    }

    return xor_all;
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums2[] = {0, 2};

    printf("Missing number in nums1: %d\n", missingNumber(nums1, 3)); // Output: 0
    printf("Missing number in nums2: %d\n", missingNumber(nums2, 2)); // Output: 1

    return 0;
}
