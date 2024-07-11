#include <stdio.h>

// Function to calculate the number of ways to climb stairs using dynamic programming
int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int dp[n+1];  // Array to store the number of ways to reach each step
    dp[0] = 0;    // There are no ways to stay at step 0 (invalid case)
    dp[1] = 1;    // Only one way to reach step 1 (one step)
    dp[2] = 2;    // Two ways to reach step 2 (1+1 or 2)

    // Fill the dp array
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];  // The number of ways to reach step i
    }

    return dp[n];  // Return the number of ways to reach step n
}

int main() {
    int n = 3;  // Example: Number of steps
    int result = climbStairs(n);
    printf("Number of ways to climb %d steps: %d\n", n, result);

    n = 4;  // Another example
    result = climbStairs(n);
    printf("Number of ways to climb %d steps: %d\n", n, result);

    return 0;
}
