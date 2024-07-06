#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to invert a binary tree
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    // Swap the left and right children
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively invert the left and right subtrees
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// Function to print level order traversal of the tree
void printLevelOrder(struct TreeNode* root) {
    if (root == NULL) return;
    
    struct TreeNode** queue = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d ", node->val);
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
    
    free(queue);
    printf("\n");
}

int main() {
    // Creating a binary tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    printf("Original tree: ");
    printLevelOrder(root);
    
    struct TreeNode* invertedRoot = invertTree(root);
    
    printf("Inverted tree: ");
    printLevelOrder(invertedRoot);
    
    return 0;
}
