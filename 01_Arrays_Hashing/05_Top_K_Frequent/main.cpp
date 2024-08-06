#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        auto compare = [&](int a, int b) { return frequencyMap[a] > frequencyMap[b]; };
        priority_queue<int, vector<int>, decltype(compare)> minHeap(compare);

        for (auto& entry : frequencyMap) {
            minHeap.push(entry.first);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return result;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    int k1 = 2;
    vector<int> result1 = solution.topKFrequent(nums1, k1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {7, 7};
    int k2 = 1;
    vector<int> result2 = solution.topKFrequent(nums2, k2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
