class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if self.stack:
            if self.stack[-1] == self.min_stack[-1]:
                self.min_stack.pop()
            self.stack.pop()

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]
        return -1  # Or some other error value

    def getMin(self) -> int:
        if self.min_stack:
            return self.min_stack[-1]
        return float('inf')  # Or some other error value

# Example usage
if __name__ == "__main__":
    minStack = MinStack()
    minStack.push(1)
    minStack.push(2)
    minStack.push(0)

    print(minStack.getMin())  # return 0
    minStack.pop()
    print(minStack.top())     # return 2
    print(minStack.getMin())  # return 1
