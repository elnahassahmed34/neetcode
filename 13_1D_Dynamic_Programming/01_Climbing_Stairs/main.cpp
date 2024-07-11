#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // Memoization table to store results of subproblems
        std::vector<int> memo(n + 1, -1);
        return climbStairsHelper(n, memo);
    }

private:
    int climbStairsHelper(int n, std::vector<int>& memo) {
        // Base cases
        if (n <= 1) return 1;
        
        // Check if result is already computed
        if (memo[n] != -1) return memo[n];
        
        // Recursive case: compute the result and store it in the memoization table
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        return memo[n];
    }
};

// Main function to test the climbStairs function
int main() {
    Solution solution;

    int n1 = 2;
    int result1 = solution.climbStairs(n1);
    std::cout << "Number of ways to climb " << n1 << " steps: " << result1 << std::endl;

    int n2 = 3;
    int result2 = solution.climbStairs(n2);
    std::cout << "Number of ways to climb " << n2 << " steps: " << result2 << std::endl;

    int n3 = 4;
    int result3 = solution.climbStairs(n3);
    std::cout << "Number of ways to climb " << n3 << " steps: " << result3 << std::endl;

    return 0;
}
