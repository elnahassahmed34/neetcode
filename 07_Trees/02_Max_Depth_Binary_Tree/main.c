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

// Function to calculate the depth of a binary tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// Helper function to print level order traversal of the tree
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
    root->right->left = newNode(4);
    
    printf("Tree: ");
    printLevelOrder(root);
    
    int depth = maxDepth(root);
    printf("Depth of the tree: %d\n", depth);
    
    return 0;
}
