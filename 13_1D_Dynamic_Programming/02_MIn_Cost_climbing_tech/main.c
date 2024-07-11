#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the minimum cost to reach the top of the staircase
int minCostClimbingStairs(int* cost, int costSize) {
    if (costSize == 0) return 0;
    if (costSize == 1) return cost[0];

    // Allocate memory for dp array
    int* dp = (int*)malloc((costSize + 1) * sizeof(int));

    // Initialize the base cases
    dp[0] = 0;
    dp[1] = 0;

    // Fill the dp array
    for (int i = 2; i <= costSize; ++i) {
        dp[i] = (dp[i - 1] + cost[i - 1] < dp[i - 2] + cost[i - 2]) ? dp[i - 1] + cost[i - 1] : dp[i - 2] + cost[i - 2];
    }

    // Print the dp array for understanding
    printf("dp array: ");
    for (int i = 0; i <= costSize; ++i) {
        printf("%d ", dp[i]);
    }
    printf("\n");

    // Result is stored in dp[costSize]
    int result = dp[costSize];

    // Free allocated memory
    free(dp);

    return result;
}

int main() {
    // Example test case 1
    int cost1[] = {1, 2, 3};
    int costSize1 = sizeof(cost1) / sizeof(cost1[0]);
    printf("Minimum cost to reach the top for cost1: %d\n", minCostClimbingStairs(cost1, costSize1));

    // Example test case 2
    int cost2[] = {1, 2, 1, 2, 1, 1, 1};
    int costSize2 = sizeof(cost2) / sizeof(cost2[0]);
    printf("Minimum cost to reach the top for cost2: %d\n", minCostClimbingStairs(cost2, costSize2));

    return 0;
}
