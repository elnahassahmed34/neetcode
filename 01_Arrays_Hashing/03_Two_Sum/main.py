from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        
        # Traverse the list to find the required pair
        for i, num in enumerate(nums):
            complement = target - num
            
            # Check if the complement exists in the map
            if complement in num_map:
                # Return the indices of the two numbers
                return [num_map[complement], i]
            
            # Add the current number and its index to the map
            num_map[num] = i
        
        # If no solution is found (though the problem guarantees a solution exists)
        return []

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [3, 4, 5, 6]
    target1 = 7
    result1 = solution.twoSum(nums1, target1)
    print(f"Example 1: {result1}")  # Output: [0, 1]
    
    # Example 2
    nums2 = [4, 5, 6]
    target2 = 10
    result2 = solution.twoSum(nums2, target2)
    print(f"Example 2: {result2}")  # Output: [0, 2]
    
    # Example 3
    nums3 = [5, 5]
    target3 = 10
    result3 = solution.twoSum(nums3, target3)
    print(f"Example 3: {result3}")  # Output: [0, 1]
