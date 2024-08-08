class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        left = 0
        max_length = 0
        
        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(s[right])
            max_length = max(max_length, right - left + 1)
        
        return max_length

# Example usage
solution = Solution()
s1 = "zxyzxyz"
s2 = "xxxx"

print(f"Length of longest substring without duplicate characters in '{s1}': {solution.lengthOfLongestSubstring(s1)}")
print(f"Length of longest substring without duplicate characters in '{s2}': {solution.lengthOfLongestSubstring(s2)}")
