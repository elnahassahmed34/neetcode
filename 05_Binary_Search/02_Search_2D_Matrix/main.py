class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False

        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1

        while left <= right:
            mid = left + (right - left) // 2
            mid_value = matrix[mid // n][mid % n]

            if mid_value == target:
                return True
            elif mid_value < target:
                left = mid + 1
            else:
                right = mid - 1

        return False

# Example usage
sol = Solution()
matrix = [[1, 2, 4, 8], [10, 11, 12, 13], [14, 20, 30, 40]]

target = 10
result = sol.searchMatrix(matrix, target)
print(f"Target {target} {'found' if result else 'not found'} in the matrix.")

target = 15
result = sol.searchMatrix(matrix, target)
print(f"Target {target} {'found' if result else 'not found'} in the matrix.")

