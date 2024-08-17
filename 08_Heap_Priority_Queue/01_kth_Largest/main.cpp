#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);  // Add all numbers in the initial list to the heap
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();  // Remove the smallest in the heap
            minHeap.push(val);  // Add the new element
        }
        return minHeap.top();  // The top of the min-heap is the kth largest element
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // Min-heap to store the top k elements
    int k;
};

int main() {
    std::vector<int> nums = {1, 2, 3, 3};
    KthLargest kthLargest(3, nums);
    
    std::cout << "After adding 3: " << kthLargest.add(3) << std::endl;  // Output: 3
    std::cout << "After adding 5: " << kthLargest.add(5) << std::endl;  // Output: 3
    std::cout << "After adding 6: " << kthLargest.add(6) << std::endl;  // Output: 3
    std::cout << "After adding 7: " << kthLargest.add(7) << std::endl;  // Output: 5
    std::cout << "After adding 8: " << kthLargest.add(8) << std::endl;  // Output: 6
    
    return 0;
}
