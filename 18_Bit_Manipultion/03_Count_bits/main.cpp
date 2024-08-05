
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0); // Initialize the result vector with size n+1
        
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1); // Calculate the number of 1s
        }
        
        return ans;
    }
};
