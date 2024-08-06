def reverse_bits(n):
    reversed_bits = 0
    for i in range(32):
        reversed_bits <<= 1
        reversed_bits |= n & 1
        n >>= 1
    return reversed_bits

# Example usage
n = 21  # Example input (00000000000000000000000000010101)
reversed_n = reverse_bits(n)

print(f"Original: {n}")  # 21
print(f"Reversed: {reversed_n}")  # 2818572288
