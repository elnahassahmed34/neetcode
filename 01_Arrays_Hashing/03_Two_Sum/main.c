#include <stdio.h>
#include <stdlib.h>

// A structure to store the element and its index
typedef struct {
    int value;
    int index;
} Element;

// A comparator function to sort the elements by value
int compare(const void* a, const void* b) {
    return ((Element*)a)->value - ((Element*)b)->value;
}

// Function to find the two indices whose elements sum up to the target
void twoSum(int* nums, int numsSize, int target, int* result) {
    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; ++i) {
        elements[i].value = nums[i];
        elements[i].index = i;
    }

    // Sort the elements by their values
    qsort(elements, numsSize, sizeof(Element), compare);

    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int sum = elements[left].value + elements[right].value;
        if (sum == target) {
            // Store the indices in ascending order
            if (elements[left].index < elements[right].index) {
                result[0] = elements[left].index;
                result[1] = elements[right].index;
            } else {
                result[0] = elements[right].index;
                result[1] = elements[left].index;
            }
            free(elements);
            return;
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    // Free allocated memory
    free(elements);
}

int main() {
    int nums1[] = {3, 4, 5, 6};
    int target1 = 7;
    int result1[2];
    twoSum(nums1, 4, target1, result1);
    printf("Example 1: [%d, %d]\n", result1[0], result1[1]); // Output: [0, 1]

    int nums2[] = {4, 5, 6};
    int target2 = 10;
    int result2[2];
    twoSum(nums2, 3, target2, result2);
    printf("Example 2: [%d, %d]\n", result2[0], result2[1]); // Output: [0, 2]

    int nums3[] = {5, 5};
    int target3 = 10;
    int result3[2];
    twoSum(nums3, 2, target3, result3);
    printf("Example 3: [%d, %d]\n", result3[0], result3[1]); // Output: [0, 1]

    return 0;
}
