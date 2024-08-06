#include <iostream>
#include <string>
#include <cctype> // for isalnum

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Step 1: Normalize the string (lowercase and remove non-alphanumeric characters)
        string normalized;
        for (char c : s) {
            if (isalnum(c)) { // Check if character is alphanumeric
                normalized += tolower(c); // Convert to lowercase
            }
        }
        
        // Step 2: Use two pointers to check palindrome
        int left = 0;
        int right = normalized.size() - 1;
        
        while (left < right) {
            if (normalized[left] != normalized[right]) {
                return false; // Characters mismatch
            }
            left++;
            right--;
        }
        
        return true; // All characters matched, it's a palindrome
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string s1 = "Was it a car or a cat I saw?";
    string s2 = "tab a cat";
    
    cout << "Example 1: " << (solution.isPalindrome(s1) ? "true" : "false") << endl;
    cout << "Example 2: " << (solution.isPalindrome(s2) ? "true" : "false") << endl;
    
    return 0;
}
