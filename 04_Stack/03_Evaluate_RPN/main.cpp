#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (token == "+") st.push(a + b);
                if (token == "-") st.push(a - b);
                if (token == "*") st.push(a * b);
                if (token == "/") st.push(a / b);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// Example usage
int main() {
    Solution sol;
    vector<string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
    int result = sol.evalRPN(tokens);
    printf("Result: %d\n", result);  // Output: 5
    return 0;
}
