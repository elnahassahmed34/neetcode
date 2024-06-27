class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # If the lengths of the strings are not equal, they cannot be anagrams
        if len(s) != len(t):
            return False
        
        # Dictionary to count the frequency of each character in the first string
        char_count = {}
        
        # Count the frequency of each character in the first string
        for char in s:
            if char in char_count:
                char_count[char] += 1
            else:
                char_count[char] = 1
        
        # Decrease the frequency for each character in the second string
        for char in t:
            if char in char_count:
                char_count[char] -= 1
                # If the count goes below zero, it means there is an extra character in t
                if char_count[char] < 0:
                    return False
            else:
                # If the character is not found in char_count, s and t are not anagrams
                return False
        
        # If we reach here, the strings are anagrams
        return True

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "racecar"
    t1 = "carrace"
    result1 = solution.isAnagram(s1, t1)
    print("Example 1:", result1)  # Output: True
    
    # Example 2
    s2 = "jar"
    t2 = "jam"
    result2 = solution.isAnagram(s2, t2)
    print("Example 1:", result2)  # Output: false
  