class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        dp = [0] * (n + 1)  # Array to store the number of ways to reach each step
        dp[0] = 0           # There are no ways to stay at step 0 (invalid case)
        dp[1] = 1           # Only one way to reach step 1 (one step)
        dp[2] = 2           # Two ways to reach step 2 (1+1 or 2)

        # Fill the dp array
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]  # The number of ways to reach step i

        return dp[n]  # Return the number of ways to reach step n

# Main function to test the climbStairs function
if __name__ == "__main__":
    solution = Solution()

    n1 = 3  # Example: Number of steps
    result1 = solution.climbStairs(n1)
    print(f"Number of ways to climb {n1} steps: {result1}")

    n2 = 4  # Another example
    result2 = solution.climbStairs(n2)
    print(f"Number of ways to climb {n2} steps: {result2}")
