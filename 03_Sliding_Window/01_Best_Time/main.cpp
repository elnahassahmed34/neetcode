#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            // Update minPrice if the current price is lower
            minPrice = min(minPrice, prices[i]);
            
            // Calculate profit if sold on the current day
            int profit = prices[i] - minPrice;
            
            // Update maxProfit if this profit is higher
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices1 = {10, 1, 5, 6, 7, 1};
    cout << "Max Profit: " << solution.maxProfit(prices1) << endl; // Output: 6

    vector<int> prices2 = {10, 8, 7, 5, 2};
    cout << "Max Profit: " << solution.maxProfit(prices2) << endl; // Output: 0

    return 0;
}
