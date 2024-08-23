#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a new 2D array for storing combinations
int** allocateCombinations(int count, int* returnColumnSizes) {
    int** combinations = (int**)malloc(count * sizeof(int*));
    return combinations;
}

// Backtracking function to find all combinations
void backtrack(int* nums, int numsSize, int target, int** combinations, int* combination, int combinationSize, int start, int* returnSize, int* returnColumnSizes) {
    if (target == 0) {
        // When a valid combination is found, copy it to the result array
        combinations[*returnSize] = (int*)malloc(combinationSize * sizeof(int));
        for (int i = 0; i < combinationSize; i++) {
            combinations[*returnSize][i] = combination[i];
        }
        returnColumnSizes[*returnSize] = combinationSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        if (nums[i] <= target) {
            combination[combinationSize] = nums[i];
            backtrack(nums, numsSize, target - nums[i], combinations, combination, combinationSize + 1, i, returnSize, returnColumnSizes);
        }
    }
}

// Main function to solve the combination sum problem
int** combinationSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int maxCombinations = 1000; // Estimate the maximum number of combinations
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));
    int** combinations = allocateCombinations(maxCombinations, *returnColumnSizes);
    
    int* combination = (int*)malloc(target * sizeof(int)); // Temporary array to store the current combination
    
    backtrack(nums, numsSize, target, combinations, combination, 0, 0, returnSize, *returnColumnSizes);
    
    free(combination);
    return combinations;
}

// Driver code to test the solution
int main() {
    int nums[] = {2, 5, 6, 9};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int returnSize;
    int* returnColumnSizes;
    
    int** result = combinationSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
    
    printf("Combinations that sum to %d:\n", target);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        free(result[i]);
    }
    
    free(result);
    free(returnColumnSizes);
    
    return 0;
}
