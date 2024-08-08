#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> chars;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]);
                ++left;
            }
            chars.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    std::string s1 = "zxyzxyz";
    std::string s2 = "xxxx";

    std::cout << "Length of longest substring without duplicate characters in '" << s1 << "': " << solution.lengthOfLongestSubstring(s1) << std::endl;
    std::cout << "Length of longest substring without duplicate characters in '" << s2 << "': " << solution.lengthOfLongestSubstring(s2) << std::endl;

    return 0;
}
