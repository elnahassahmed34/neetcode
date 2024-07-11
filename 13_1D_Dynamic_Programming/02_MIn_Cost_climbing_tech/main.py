class Solution:
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        
        # Special case for small inputs
        if n == 0:
            return 0
        if n == 1:
            return cost[0]
        
        dp = [0] * (n + 1)  # Array to store the minimum cost to reach each step

        # Initialize the base cases
        dp[0] = 0
        dp[1] = 0

        # Fill the dp array
        for i in range(2, n + 1):
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])

        return dp[n]  # Return the minimum cost to reach the top

if __name__ == "__main__":
    solution = Solution()

    cost1 = [1, 2, 3]  # Example 1
    print(f"Minimum cost to climb the stairs (Example 1): {solution.minCostClimbingStairs(cost1)}")

    cost2 = [1, 2, 1, 2, 1, 1, 1]  # Example 2
    print(f"Minimum cost to climb the stairs (Example 2): {solution.minCostClimbingStairs(cost2)}")
