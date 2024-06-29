def search(nums, target):
    """
    Perform binary search to find the target in a sorted list of integers.

    :param nums: List of integers sorted in ascending order
    :param target: Integer to search for
    :return: Index of target if found, otherwise -1
    """
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if nums[mid] == target:
            return mid  # Target found
        elif nums[mid] < target:
            left = mid + 1  # Search in the right half
        else:
            right = mid - 1  # Search in the left half

    return -1  # Target not found

# Example usage
nums1 = [-1, 0, 2, 4, 6, 8]
target1 = 4
print("Output:", search(nums1, target1))  # Output: 3

nums2 = [-1, 0, 2, 4, 6, 8]
target2 = 3
print("Output:", search(nums2, target2))  # Output: -1
