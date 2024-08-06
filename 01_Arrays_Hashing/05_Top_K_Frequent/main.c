#include <stdio.h>
#include <stdlib.h>

// Structure to hold the element and its frequency
typedef struct {
    int element;
    int frequency;
} ElementFreq;

// Comparison function for qsort (sorting based on frequency)
int compare(const void *a, const void *b) {
    return ((ElementFreq *)b)->frequency - ((ElementFreq *)a)->frequency;
}

// Function to find the top k frequent elements
void topKFrequent(int *nums, int numsSize, int k, int *result) {
    // Step 1: Count the frequency of each element
    ElementFreq *freqArray = (ElementFreq *)malloc(numsSize * sizeof(ElementFreq));
    int freqSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < freqSize; j++) {
            if (freqArray[j].element == nums[i]) {
                freqArray[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freqArray[freqSize].element = nums[i];
            freqArray[freqSize].frequency = 1;
            freqSize++;
        }
    }

    // Step 2: Sort the frequency array based on frequency (descending order)
    qsort(freqArray, freqSize, sizeof(ElementFreq), compare);

    // Step 3: Extract the top k elements
    for (int i = 0; i < k; i++) {
        result[i] = freqArray[i].element;
    }

    // Free allocated memory
    free(freqArray);
}

// Example usage
int main() {
    int nums1[] = {1, 2, 2, 3, 3, 3};
    int k1 = 2;
    int result1[2];

    topKFrequent(nums1, sizeof(nums1) / sizeof(nums1[0]), k1, result1);
    for (int i = 0; i < k1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");

    int nums2[] = {7, 7};
    int k2 = 1;
    int result2[1];

    topKFrequent(nums2, sizeof(nums2) / sizeof(nums2[0]), k2, result2);
    for (int i = 0; i < k2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");

    return 0;
}
