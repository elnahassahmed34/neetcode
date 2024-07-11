#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to calculate the minimum cost to reach the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Special case for small inputs
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        
        vector<int> dp(n + 1, 0);  // Array to store the minimum cost to reach each step

        // Initialize the base cases
        dp[0] = 0;
        dp[1] = 0;

        // Fill the dp array
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];  // Return the minimum cost to reach the top
    }
};

int main() {
    Solution solution;

    vector<int> cost1 = {1, 2, 3};  // Example 1
    cout << "Minimum cost to climb the stairs (Example 1): " << solution.minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {1, 2, 1, 2, 1, 1, 1};  // Example 2
    cout << "Minimum cost to climb the stairs (Example 2): " << solution.minCostClimbingStairs(cost2) << endl;

    return 0;
}
