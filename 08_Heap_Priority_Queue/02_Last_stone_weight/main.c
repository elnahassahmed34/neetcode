#include <stdio.h>

void sortDesc(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        sortDesc(stones, stonesSize);

        if (stones[0] == stones[1]) {
            // Both stones are destroyed
            for (int i = 2; i < stonesSize; ++i) {
                stones[i - 2] = stones[i];
            }
            stonesSize -= 2;
        } else {
            // Smash stones[0] and stones[1]
            stones[0] = stones[0] - stones[1];
            for (int i = 2; i < stonesSize; ++i) {
                stones[i - 1] = stones[i];
            }
            stonesSize -= 1;
        }
    }

    return stonesSize == 1 ? stones[0] : 0;
}

int main() {
    int stones1[] = {2, 3, 6, 2, 4};
    int size1 = sizeof(stones1) / sizeof(stones1[0]);

    int stones2[] = {1, 2};
    int size2 = sizeof(stones2) / sizeof(stones2[0]);

    printf("Last stone weight (Example 1): %d\n", lastStoneWeight(stones1, size1));
    printf("Last stone weight (Example 2): %d\n", lastStoneWeight(stones2, size2));

    return 0;
}
