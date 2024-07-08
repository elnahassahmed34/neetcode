class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.max_diameter = 0
        self.compute_height(root)
        return self.max_diameter
    
    def compute_height(self, node: TreeNode) -> int:
        if not node:
            return 0
        
        left_height = self.compute_height(node.left)
        right_height = self.compute_height(node.right)
        
        # Update the maximum diameter found so far
        self.max_diameter = max(self.max_diameter, left_height + right_height)
        
        # Return the height of the current node's subtree
        return 1 + max(left_height, right_height)

# Utility function to create a binary tree from an array representation
def create_binary_tree(arr):
    if not arr:
        return None
    
    nodes = [None if val is None else TreeNode(val) for val in arr]
    
    root = nodes[0]
    idx = 0
    for node in nodes:
        if node:
            left_idx = 2 * idx + 1
            right_idx = 2 * idx + 2
            if left_idx < len(nodes):
                node.left = nodes[left_idx]
            if right_idx < len(nodes):
                node.right = nodes[right_idx]
            idx += 1
    
    return root

# Example usage
if __name__ == "__main__":
    # Example 1: [1,null,2,3,4,5]
    arr1 = [1, None, 2, 3, 4, 5]
    root1 = create_binary_tree(arr1)
    
    solution = Solution()
    diameter1 = solution.diameterOfBinaryTree(root1)
    print("Diameter of Example 1:", diameter1)
    
    # Example 2: [1,2,3]
    arr2 = [1, 2, 3]
    root2 = create_binary_tree(arr2)
    
    diameter2 = solution.diameterOfBinaryTree(root2)
    print("Diameter of Example 2:", diameter2)
