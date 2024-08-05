class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n > 0:
            if n & 1:  # Check the least significant bit
                count += 1
            n >>= 1  # Right shift n by 1 bit
        return count

# Testing the implementation
sol = Solution()

n1 = 0b00000000000000000000000000010111
n2 = 0b01111111111111111111111111111101

print(f"Number of 1 bits in {bin(n1)} : {sol.hammingWeight(n1)}")
print(f"Number of 1 bits in {bin(n2)} : {sol.hammingWeight(n2)}")
