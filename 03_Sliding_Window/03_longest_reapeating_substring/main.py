class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        max_freq = 0
        left = 0
        max_length = 0

        for right in range(len(s)):
            count[s[right]] = count.get(s[right], 0) + 1
            max_freq = max(max_freq, count[s[right]])

            while (right - left + 1) - max_freq > k:
                count[s[left]] -= 1
                left += 1

            max_length = max(max_length, right - left + 1)

        return max_length

# Example usage
solution = Solution()
s1 = "XYYX"
k1 = 2
print(f"Length of longest substring after replacements in '{s1}': {solution.characterReplacement(s1, k1)}")

s2 = "AAABABB"
k2 = 1
print(f"Length of longest substring after replacements in '{s2}': {solution.characterReplacement(s2, k2)}")
