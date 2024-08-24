class Solution:
    def encode(self, strs):
        encoded = ""
        for s in strs:
            encoded += str(len(s)) + "#" + s
        return encoded

    def decode(self, s):
        decoded = []
        i = 0
        while i < len(s):
            # Find the position of the delimiter '#'
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            i = j + 1
            decoded.append(s[i:i + length])
            i += length
        return decoded

# Example usage
solution = Solution()
input1 = ["neet", "code", "love", "you"]

encoded = solution.encode(input1)
print(f"Encoded: {encoded}")

decoded = solution.decode(encoded)
print(f"Decoded: {decoded}")
