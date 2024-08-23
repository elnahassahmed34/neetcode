class Solution:
    def subsets(self, nums):
        result = []
        self.generateSubsets(nums, 0, [], result)
        return result
    
    def generateSubsets(self, nums, index, currentSubset, result):
        result.append(list(currentSubset))
        
        for i in range(index, len(nums)):
            currentSubset.append(nums[i])
            self.generateSubsets(nums, i + 1, currentSubset, result)
            currentSubset.pop()

# Example usage
solution = Solution()
nums = [1, 2, 3]
print(solution.subsets(nums))
