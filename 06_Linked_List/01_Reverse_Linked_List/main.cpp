#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to reverse the singly linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // Previous node, initially null
        ListNode* current = head; // Current node, starts from head
        ListNode* next = nullptr; // Next node, initially null

        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move the previous node to current
            current = next;       // Move to the next node
        }

        return prev; // New head of the reversed list
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* tail = dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Example 1
    std::vector<int> nums1 = {0, 1, 2, 3};
    ListNode* head1 = createList(nums1);
    std::cout << "Original List 1: ";
    printList(head1);

    ListNode* reversedHead1 = solution.reverseList(head1);
    std::cout << "Reversed List 1: ";
    printList(reversedHead1);

    // Example 2
    std::vector<int> nums2 = {};
    ListNode* head2 = createList(nums2);
    std::cout << "Original List 2: ";
    printList(head2);

    ListNode* reversedHead2 = solution.reverseList(head2);
    std::cout << "Reversed List 2: ";
    printList(reversedHead2);

    return 0;
}
