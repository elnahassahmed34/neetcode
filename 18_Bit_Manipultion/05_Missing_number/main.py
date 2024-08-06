from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor_all = 0
        n = len(nums)
        
        for i in range(n + 1):
            xor_all ^= i
            
        for num in nums:
            xor_all ^= num
            
        return xor_all

# Example usage
sol = Solution()
nums1 = [1, 2, 3]
nums2 = [0, 2]

print(f"Missing number in nums1: {sol.missingNumber(nums1)}") # Output: 0
print(f"Missing number in nums2: {sol.missingNumber(nums2)}") # Output: 1
