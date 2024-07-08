#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        computeHeight(root, max_diameter);
        return max_diameter;
    }
    
    int computeHeight(TreeNode* node, int& max_diameter) {
        if (node == nullptr) return 0;
        
        int left_height = computeHeight(node->left, max_diameter);
        int right_height = computeHeight(node->right, max_diameter);
        
        // Update the maximum diameter found so far
        max_diameter = std::max(max_diameter, left_height + right_height);
        
        // Return the height of the current node's subtree
        return 1 + std::max(left_height, right_height);
    }
};

// Utility function to create a binary tree from an array representation
TreeNode* createBinaryTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(arr[i]);
    root->left = createBinaryTree(arr, n, 2*i + 1);
    root->right = createBinaryTree(arr, n, 2*i + 2);

    return root;
}

// Utility function to delete a binary tree to free memory
void deleteBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

int main() {
    // Example 1: [1,null,2,3,4,5]
    int arr1[] = {1, -1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    TreeNode* root1 = createBinaryTree(arr1, n1, 0);

    Solution solution;
    int diameter1 = solution.diameterOfBinaryTree(root1);
    std::cout << "Diameter of Example 1: " << diame
