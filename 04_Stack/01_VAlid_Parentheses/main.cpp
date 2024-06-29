#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;

        for (char ch : s) {
            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                bracketStack.push(ch);
            } else {
                // Check if the stack is empty (no matching opening bracket)
                if (bracketStack.empty()) {
                    return false;
                }

                // Pop the top element and check if it matches the closing bracket
                char top = bracketStack.top();
                bracketStack.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If the stack is empty, all brackets were matched properly
        return bracketStack.empty();
    }
};

int main() {
    Solution solution;
    string s1 = "[]";
    cout << "Input: " << s1 << ", Output: " << (solution.isValid(s1) ? "true" : "false") << endl;

    string s2 = "([{}])";
    cout << "Input: " << s2 << ", Output: " << (solution.isValid(s2) ? "true" : "false") << endl;

    string s3 = "[(])";
    cout << "Input: " << s3 << ", Output: " << (solution.isValid(s3) ? "true" : "false") << endl;

    return 0;
}
