#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive approach to find maximum depth of binary tree
    int maxDepthRecursive(TreeNode* root) {
        // Base case: if root is null, return 0
        if (root == nullptr) {
            return 0;
        }
        // Recursive calls to find depths of left and right subtrees
        int leftDepth = maxDepthRecursive(root->left);
        int rightDepth = maxDepthRecursive(root->right);
        // Depth of current node is 1 (for current node) + max depth of left or right subtree
        //when it returns it accumlates the result
        return 1 + max(leftDepth, rightDepth);
    }
    
    // Iterative approach to find maximum depth of binary tree using BFS
    int maxDepthIterative(TreeNode* root) {
        // Base case: if root is null, return 0
        if (root == nullptr) {
            return 0;
        }
        
        // Initialize queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            // Increment depth for each level of the tree
            ++depth;
            int levelSize = q.size();
            // Process all nodes at current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                // Enqueue left and right children if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return depth;
    }
    
    // Wrapper function to call the recursive implementation
    int maxDepth(TreeNode* root) {
        return maxDepthRecursive(root);
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Main function to test the implementation
int main() {
    // Example tree creation
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);

    // Print the original tree structure
    cout << "Original Tree:" << endl;
    cout << "   1" << endl;
    cout << "  / \\" << endl;
    cout << " 2   3" << endl;
    cout << "    /" << endl;
    cout << "   4" << endl;

    // Create an instance of the Solution class
    Solution sol;
    
    // Calculate and print the depth of the tree using both approaches
    cout << "Depth (Recursive): " << sol.maxDepthRecursive(root) << endl;
    cout << "Depth (Iterative): " << sol.maxDepthIterative(root) << endl;

    return 0;
}
