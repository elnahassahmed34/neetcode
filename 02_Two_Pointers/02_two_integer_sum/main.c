#include <stdio.h>

void twoSum(int* numbers, int numbersSize, int target, int* result) {
    int left = 0;
    int right = numbersSize - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];
        if (current_sum == target) {
            result[0] = left + 1;  // Returning 1-indexed result
            result[1] = right + 1; // Returning 1-indexed result
            return;
        } else if (current_sum < target) {
            left++; // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }

    result[0] = -1; // Fallback, though the problem guarantees exactly one solution
    result[1] = -1; // Fallback, though the problem guarantees exactly one solution
}

int main() {
    int numbers[] = {1, 2, 3, 4};
    int target = 3;
    int result[2];
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    twoSum(numbers, numbersSize, target, result);

    printf("%d %d\n", result[0], result[1]);

    return 0;
}
