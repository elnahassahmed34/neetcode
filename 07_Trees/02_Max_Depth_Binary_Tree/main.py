class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        
        return 1 + max(left_depth, right_depth)

# Helper function to create a binary tree
def newNode(val):
    return TreeNode(val)

# Helper function to print level order traversal
def printLevelOrder(root):
    if root is None:
        return
    
    queue = [root]
    
    while queue:
        node = queue.pop(0)
        print(node.val, end=" ")
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    print()

if __name__ == "__main__":
    # Creating a binary tree
    root = newNode(1)
    root.left = newNode(2)
    root.right = newNode(3)
    root.right.left = newNode(4)
    
    print("Tree: ", end="")
    printLevelOrder(root)
    
    solution = Solution()
    depth = solution.maxDepth(root)
    print("Depth of the tree:", depth)
