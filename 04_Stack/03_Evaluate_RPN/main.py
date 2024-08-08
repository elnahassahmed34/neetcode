class Solution:
    def evalRPN(self, tokens):
        stack = []

        for token in tokens:
            if token in "+-*/":
                b = stack.pop()
                a = stack.pop()
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                elif token == "/":
                    # Python division truncates towards negative infinity by default, 
                    # so we need to use int() to ensure truncation towards zero.
                    stack.append(int(a / b))
            else:
                stack.append(int(token))

        return stack[0]

# Example usage
if __name__ == "__main__":
    sol = Solution()
    tokens = ["1", "2", "+", "3", "*", "4", "-"]
    result = sol.evalRPN(tokens)
    print(f"Result: {result}")  # Output: 5
