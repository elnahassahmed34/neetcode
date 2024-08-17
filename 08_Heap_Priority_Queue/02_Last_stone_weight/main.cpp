#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a max-heap using priority_queue
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // Continue until there is more than one stone left
        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); // Get the heaviest stone
            maxHeap.pop();
            int stone2 = maxHeap.top(); // Get the second heaviest stone
            maxHeap.pop();

            // If they are not equal, push the difference back into the heap
            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }

        // If there is one stone left, return its weight, otherwise return 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

int main() {
    Solution solution;
    vector<int> stones1 = {2, 3, 6, 2, 4};
    vector<int> stones2 = {1, 2};

    cout << "Last stone weight (Example 1): " << solution.lastStoneWeight(stones1) << endl;
    cout << "Last stone weight (Example 2): " << solution.lastStoneWeight(stones2) << endl;

    return 0;
}
