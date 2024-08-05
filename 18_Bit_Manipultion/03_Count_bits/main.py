class Solution:
    def countBits(self, n: int) -> list[int]:
        ans = [0] * (n + 1) # Initialize the result list with size n+1
        
        for i in range(1, n + 1):
            ans[i] = ans[i >> 1] + (i & 1) # Calculate the number of 1s
        
        return ans
