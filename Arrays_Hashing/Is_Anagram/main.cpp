#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    // Function to check if two strings are anagrams
    bool isAnagram(const std::string& s, const std::string& t) {
        // If the lengths of the strings are not equal, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Use a hash map to count the frequency of each character in the first string
        std::unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        // Decrease the frequency for each character in the second string
        for (char c : t) {
            // If a character is found that is not in the first string or is used up,
            // the strings are not anagrams
            if (charCount[c] == 0) {
                return false;
            }
            charCount[c]--;
        }

        // If we reach here, the strings are anagrams
        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::string s1 = "racecar";
    std::string t1 = "carrace";
    bool result1 = solution.isAnagram(s1, t1);
    std::cout << "Example 1: " << (result1 ? "true" : "false") << std::endl; // Output: true

    // Test case 2
    std::string s2 = "jar";
    std::string t2 = "jam";
    bool result2 = solution.isAnagram(s2, t2);
    std::cout << "Example 2: " << (result2 ? "true" : "false") << std::endl; // Output: false

    return 0;
}
