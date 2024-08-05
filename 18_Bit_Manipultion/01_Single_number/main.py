class Solution:
    def singleNumber(self, nums):
        result = 0
        for num in nums:
            result ^= num
        return result

if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [3, 2, 3]
    print(f"Single number in {nums1} is: {sol.singleNumber(nums1)}") # Output: 2
    
    nums2 = [7, 6, 6, 7, 8]
    print(f"Single number in {nums2} is: {sol.singleNumber(nums2)}") # Output: 8
    
    nums3 = [1, 1, 2, 2, 3]
    print(f"Single number in {nums3} is: {sol.singleNumber(nums3)}") # Output: 3
