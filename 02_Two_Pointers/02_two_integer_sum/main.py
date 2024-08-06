class Solution:
    def twoSum(self, numbers, target):
        left = 0
        right = len(numbers) - 1

        while left < right:
            current_sum = numbers[left] + numbers[right]
            if current_sum == target:
                return [left + 1, right + 1]  # Returning 1-indexed result
            elif current_sum < target:
                left += 1  # Move left pointer to the right
            else:
                right -= 1  # Move right pointer to the left

        return []  # Just a fallback, though the problem guarantees exactly one solution

# Example usage
solution = Solution()
numbers = [1, 2, 3, 4]
target = 3
result = solution.twoSum(numbers, target)
print(result)
