#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<string> strs1 = {"act", "pots", "tops", "cat", "stop", "hat"};
    vector<vector<string>> result1 = sol.groupAnagrams(strs1);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result1) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    vector<string> strs2 = {"x"};
    vector<vector<string>> result2 = sol.groupAnagrams(strs2);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result2) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    vector<string> strs3 = {""};
    vector<vector<string>> result3 = sol.groupAnagrams(strs3);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result3) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
