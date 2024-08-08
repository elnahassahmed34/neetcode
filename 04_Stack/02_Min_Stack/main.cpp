#include <stack>
#include <limits.h>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        }
    }
    
    void pop() {
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }

private:
    std::stack<int> s;
    std::stack<int> minS;
};

// Example usage
int main() {
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    
    std::cout << minStack.getMin() << std::endl; // return 0
    minStack.pop();
    std::cout << minStack.top() << std::endl;    // return 2
    std::cout << minStack.getMin() << std::endl; // return 1
    
    return 0;
}
