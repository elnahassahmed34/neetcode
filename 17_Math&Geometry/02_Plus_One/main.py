class Solution:
    def plusOne(self, digits):
        n = len(digits)
        
        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        
        return [1] + digits

# Test cases
sol = Solution()

digits1 = [1, 2, 3, 4]
result1 = sol.plusOne(digits1)
print(f"Result: {result1}")

digits2 = [9, 9, 9]
result2 = sol.plusOne(digits2)
print(f"Result: {result2}")
