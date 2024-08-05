#include <stdio.h>
#include <stdlib.h>

void plusOne(int* digits, int digitsSize, int** returnSize, int* returnArraySize) {
    for (int i = digitsSize - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digits;
            *returnArraySize = digitsSize;
            return;
        }
        digits[i] = 0;
    }

    *returnArraySize = digitsSize + 1;
    *returnSize = (int*)malloc((*returnArraySize) * sizeof(int));
    (*returnSize)[0] = 1;
    for (int i = 1; i < *returnArraySize; ++i) {
        (*returnSize)[i] = 0;
    }
}

int main() {
    int digits1[] = {1, 2, 3, 4};
    int size1 = sizeof(digits1) / sizeof(digits1[0]);
    int* returnSize1;
    int returnArraySize1;

    plusOne(digits1, size1, &returnSize1, &returnArraySize1);

    printf("Result: ");
    for (int i = 0; i < returnArraySize1; ++i) {
        printf("%d ", returnSize1[i]);
    }
    printf("\n");

    int digits2[] = {9, 9, 9};
    int size2 = sizeof(digits2) / sizeof(digits2[0]);
    int* returnSize2;
    int returnArraySize2;

    plusOne(digits2, size2, &returnSize2, &returnArraySize2);

    printf("Result: ");
    for (int i = 0; i < returnArraySize2; ++i) {
        printf("%d ", returnSize2[i]);
    }
    printf("\n");

    // Free allocated memory for returnSize
    if (returnArraySize1 > size1) free(returnSize1);
    if (returnArraySize2 > size2) free(returnSize2);

    return 0;
}
