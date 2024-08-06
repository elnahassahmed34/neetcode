from collections import Counter
import heapq

class Solution:
    def topKFrequent(self, nums, k):
        count = Counter(nums)
        return heapq.nlargest(k, count.keys(), key=count.get)

# Example usage
solution = Solution()
nums1 = [1, 2, 2, 3, 3, 3]
k1 = 2
result1 = solution.topKFrequent(nums1, k1)
print(result1)

nums2 = [7, 7]
k2 = 1
result2 = solution.topKFrequent(nums2, k2)
print(result2)
