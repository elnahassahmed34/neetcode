def is_valid(s):
    stack = []
    matching_bracket = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in matching_bracket:
            # Check if stack is empty or top of stack doesn't match
            if not stack or stack[-1] != matching_bracket[char]:
                return False
            stack.pop()
        else:
            stack.append(char)

    return not stack

# Example usage
print(is_valid("[]"))       # Output: True
print(is_valid("([{}])"))   # Output: True
print(is_valid("[(])"))     # Output: False
