#include <stdio.h>
#include <stdlib.h>

void generateSubsets(int* nums, int numsSize, int index, int* currentSubset, int currentSize, int** result, int* returnSize, int* columnSizes) {
    result[*returnSize] = (int*)malloc(currentSize * sizeof(int));
    for (int i = 0; i < currentSize; i++) {
        result[*returnSize][i] = currentSubset[i];
    }
    columnSizes[*returnSize] = currentSize;
    (*returnSize)++;

    for (int i = index; i < numsSize; i++) {
        currentSubset[currentSize] = nums[i];
        generateSubsets(nums, numsSize, i + 1, currentSubset, currentSize + 1, result, returnSize, columnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** columnSizes) {
    int maxSubsetCount = 1 << numsSize;
    int** result = (int**)malloc(maxSubsetCount * sizeof(int*));
    *columnSizes = (int*)malloc(maxSubsetCount * sizeof(int));
    int* currentSubset = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    generateSubsets(nums, numsSize, 0, currentSubset, 0, result, returnSize, *columnSizes);

    free(currentSubset);
    return result;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* columnSizes;
    
    int** result = subsets(nums, numsSize, &returnSize, &columnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < columnSizes[i] - 1) printf(",");
        }
        printf("]");
        if (i < returnSize - 1) printf(",");
    }
    printf("]\n");

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(columnSizes);

    return 0;
}
