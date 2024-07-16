def sum_of_squares(n):
    sum = 0
    while n > 0:
        digit = n % 10
        sum += digit * digit
        n //= 10
    return sum

def is_happy(n):
    seen_numbers = set()
    while n != 1 and n not in seen_numbers:
        seen_numbers.add(n)
        n = sum_of_squares(n)
    return n == 1

# Testing the function
test1 = 100
test2 = 101

print(f"Is {test1} a happy number? {'True' if is_happy(test1) else 'False'}")
print(f"Is {test2} a happy number? {'True' if is_happy(test2) else 'False'}")
