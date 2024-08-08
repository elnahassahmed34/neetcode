#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int max_freq = 0;
        int left = 0, max_length = 0;

        for (int right = 0; right < s.size(); ++right) {
            count[s[right]]++;
            max_freq = max(max_freq, count[s[right]]);

            while ((right - left + 1) - max_freq > k) {
                count[s[left]]--;
                left++;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

// Example usage
int main() {
    Solution solution;
    string s1 = "XYYX";
    int k1 = 2;
    cout << "Length of longest substring after replacements in '" << s1 << "': " << solution.characterReplacement(s1, k1) << endl;

    string s2 = "AAABABB";
    int k2 = 1;
    cout << "Length of longest substring after replacements in '" << s2 << "': " << solution.characterReplacement(s2, k2) << endl;

    return 0;
}
