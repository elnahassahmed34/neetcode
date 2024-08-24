class Solution:
    def maxArea(self, heights):
        left = 0  # Left pointer
        right = len(heights) - 1  # Right pointer
        max_area = 0  # To store the maximum area found

        while left < right:
            # Calculate the area with the current left and right bars
            height = min(heights[left], heights[right])
            width = right - left
            current_area = height * width

            # Update max_area if a larger area is found
            max_area = max(max_area, current_area)

            # Move the pointer pointing to the shorter bar inward
            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1

        return max_area

# Example usage
solution = Solution()
heights1 = [1,7,2,5,4,7,3,6]
print("Max Water Container Area:", solution.maxArea(heights1))  # Output: 36

heights2 = [2,2,2]
print("Max Water Container Area:", solution.maxArea(heights2))  # Output: 4
