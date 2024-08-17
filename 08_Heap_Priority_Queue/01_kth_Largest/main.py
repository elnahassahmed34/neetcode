import heapq

class KthLargest:
    def __init__(self, k, nums):
        self.k = k
        self.minHeap = []
        for num in nums:
            self.add(num)

    def add(self, val):
        if len(self.minHeap) < self.k:
            heapq.heappush(self.minHeap, val)
        elif val > self.minHeap[0]:
            heapq.heapreplace(self.minHeap, val)
        return self.minHeap[0]

# Example usage
if __name__ == "__main__":
    nums = [1, 2, 3, 3]
    kthLargest = KthLargest(3, nums)
    
    print("After adding 3:", kthLargest.add(3))  # Output: 3
    print("After adding 5:", kthLargest.add(5))  # Output: 3
    print("After adding 6:", kthLargest.add(6))  # Output: 3
    print("After adding 7:", kthLargest.add(7))  # Output: 5
    print("After adding 8:", kthLargest.add(8))  # Output: 6
