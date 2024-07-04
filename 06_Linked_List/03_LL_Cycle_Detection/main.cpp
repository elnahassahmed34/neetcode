#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};

// Helper function to create a linked list with a cycle
ListNode* createLinkedListWithCycle(vector<int>& values, int index) {
    if (values.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    ListNode* cycleStart = nullptr;
    
    for (int i = 1; i < values.size(); ++i) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
        if (i == index) {
            cycleStart = tail;
        }
    }
    
    if (cycleStart != nullptr) {
        tail->next = cycleStart;
    }
    
    return head;
}

// Main function to test the solution
int main() {
    Solution solution;
    
    // Example 1: [1,2,3,4], index = 1 (cycle at index 1)
    vector<int> values1 = {1, 2, 3, 4};
    int index1 = 1;
    ListNode* head1 = createLinkedListWithCycle(values1, index1);
    bool hasCycle1 = solution.hasCycle(head1);
    cout << "Example 1: " << (hasCycle1 ? "true" : "false") << endl;
    
    // Example 2: [1,2], index = -1 (no cycle)
    vector<int> values2 = {1, 2};
    int index2 = -1;
    ListNode* head2 = createLinkedListWithCycle(values2, index2);
    bool hasCycle2 = solution.hasCycle(head2);
    cout << "Example 2: " << (hasCycle2 ? "true" : "false") << endl;
    
    return 0;
}
