#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to free the memory allocated for the linked list nodes
void freeList(struct ListNode* head) {
    struct ListNode* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Function to detect cycle in a linked list
int hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return 0; // No cycle if head is NULL or there's only one node
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    
    while (fast != slow) {
        if (fast == NULL || fast->next == NULL) {
            return 0; // No cycle if fast pointer reaches end of list
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return 1; // Cycle detected
}

// Helper function to create a linked list with a cycle
struct ListNode* createLinkedListWithCycle(int* values, int length, int index) {
    if (values == NULL || length <= 0) {
        return NULL;
    }
    
    struct ListNode* head = createNode(values[0]);
    struct ListNode* tail = head;
    struct ListNode* cycleStart = NULL;
    
    // Create the linked list
    for (int i = 1; i < length; ++i) {
        tail->next = createNode(values[i]);
        tail = tail->next;
        if (i == index) {
            cycleStart = tail;
        }
    }
    
    // Create cycle if index is valid
    if (cycleStart != NULL) {
        tail->next = cycleStart;
    }
    
    return head;
}

// Main function to test the solution
int main() {
    // Example 1: [1,2,3,4], index = 1 (cycle at index 1)
    int values1[] = {1, 2, 3, 4};
    int length1 = sizeof(values1) / sizeof(values1[0]);
    int index1 = 1;
    struct ListNode* head1 = createLinkedListWithCycle(values1, length1, index1);
    int hasCycle1 = hasCycle(head1);
    printf("Example 1: %s\n", hasCycle1 ? "true" : "false");
    freeList(head1);

    // Example 2: [1,2], index = -1 (no cycle)
    int values2[] = {1, 2};
    int length2 = sizeof(values2) / sizeof(values2[0]);
    int index2 = -1;
    struct ListNode* head2 = createLinkedListWithCycle(values2, length2, index2);
    int hasCycle2 = hasCycle(head2);
    printf("Example 2: %s\n", hasCycle2 ? "true" : "false");
    freeList(head2);

    return 0;
}
