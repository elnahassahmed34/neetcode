#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to form the new merged list
        ListNode dummy;
        ListNode* tail = &dummy;

        // Traverse both lists and append the smaller value node to the tail
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // If one list is exhausted, append the other list to the tail
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the merged list starting from the next node of dummy
        return dummy.next;
    }
};

// Helper function to create a new list node
ListNode* createNode(int val) {
    return new ListNode(val);
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    // Create list1: 1 -> 2 -> 4
    ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    // Create list2: 1 -> 3 -> 5
    ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(5);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list: 1 -> 1 -> 2 -> 3 -> 4 -> 5
    printList(mergedList);

    return 0;
}
