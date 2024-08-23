class Solution:
    def combinationSum(self, nums, target):
        result = []
        self.backtrack(nums, target, 0, [], result)
        return result

    def backtrack(self, nums, target, start, current_combination, result):
        if target == 0:
            result.append(list(current_combination))
            return
        if target < 0:
            return

        for i in range(start, len(nums)):
            current_combination.append(nums[i])
            self.backtrack(nums, target - nums[i], i, current_combination, result)
            current_combination.pop()

# Example usage
solution = Solution()
nums = [2, 5, 6, 9]
target = 9
print(solution.combinationSum(nums, target))
