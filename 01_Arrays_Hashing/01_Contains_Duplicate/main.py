def has_duplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False

# Test cases
nums1 = [1, 2, 3, 3]
nums2 = [1, 2, 3, 4]

print("Example 1:", has_duplicate(nums1))  # Output: True
print("Example 2:", has_duplicate(nums2))  # Output: False
