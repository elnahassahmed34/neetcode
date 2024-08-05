#include <stdio.h>
#include <stdlib.h>

// Function to count the number of 1 bits in binary representation of each number from 0 to n
int* countBits(int n, int* returnSize) {
    // Allocate memory for the result array
    int* ans = (int*)malloc((n + 1) * sizeof(int));
    
    // Initialize the result array
    for (int i = 0; i <= n; ++i) {
        ans[i] = 0;
    }
    
    // Compute the number of 1 bits for each number
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    
    // Set the return size
    *returnSize = n + 1;
    
    return ans;
}

// Function to print the result array
void printBits(int* bits, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", bits[i]);
    }
    printf("\n");
}

int main() {
    int n = 5; // Example input
    int returnSize;
    
    // Get the number of 1 bits
    int* result = countBits(n, &returnSize);
    
    // Print the result
    printBits(result, returnSize);
    
    // Free the allocated memory
    free(result);
    
    return 0;
}
