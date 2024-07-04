#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse the singly linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL; // Previous node, initially NULL
    struct ListNode* current = head; // Current node, starts from head
    struct ListNode* next = NULL; // Next node, initially NULL

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current; // Move the previous node to current
        current = next; // Move to the next node
    }

    return prev; // New head of the reversed list
}

// Helper function to create a linked list from an array
struct ListNode* createList(int* nums, int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = nums[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Helper function to free the memory allocated for a linked list
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Example 1
    int nums1[] = {0, 1, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    struct ListNode* head1 = createList(nums1, size1);
    printf("Original List 1: ");
    printList(head1);

    struct ListNode* reversedHead1 = reverseList(head1);
    printf("Reversed List 1: ");
    printList(reversedHead1);
    freeList(reversedHead1);

    // Example 2
    int nums2[] = {};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    struct ListNode* head2 = createList(nums2, size2);
    printf("Original List 2: ");
    printList(head2);

    struct ListNode* reversedHead2 = reverseList(head2);
    printf("Reversed List 2: ");
    printList(reversedHead2);
    freeList(reversedHead2);

    return 0;
}
