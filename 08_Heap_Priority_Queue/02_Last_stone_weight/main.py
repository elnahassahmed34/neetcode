import heapq

class Solution:
    def lastStoneWeight(self, stones):
        # Convert all stone weights to negative for max-heap simulation
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            stone1 = -heapq.heappop(stones)  # Get the heaviest stone
            stone2 = -heapq.heappop(stones)  # Get the second heaviest stone

            if stone1 != stone2:
                heapq.heappush(stones, -(stone1 - stone2))

        return -stones[0] if stones else 0

# Example usage:
solution = Solution()
stones1 = [2, 3, 6, 2, 4]
stones2 = [1, 2]

print("Last stone weight (Example 1):", solution.lastStoneWeight(stones1))
print("Last stone weight (Example 2):", solution.lastStoneWeight(stones2))
