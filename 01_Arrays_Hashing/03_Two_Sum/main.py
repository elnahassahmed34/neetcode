def is_palindrome(s: str) -> bool:
    # Normalize the string: convert to lowercase and filter out non-alphanumeric characters
    filtered_chars = [c.lower() for c in s if c.isalnum()]
    
    # Use two pointers
    left, right = 0, len(filtered_chars) - 1
    
    # Compare characters from both ends
    while left < right:
        if filtered_chars[left] != filtered_chars[right]:
            return False
        left += 1
        right -= 1
    
    return True

# Test cases
s1 = "Was it a car or a cat I saw?"
s2 = "tab a cat"

print(f"Example 1: {is_palindrome(s1)}")  # Output: True
print(f"Example 2: {is_palindrome(s2)}")  # Output: False
