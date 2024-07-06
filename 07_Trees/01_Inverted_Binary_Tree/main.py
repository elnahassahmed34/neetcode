class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        
        # Swap the left and right children
        root.left, root.right = root.right, root.left
        
        # Recursively invert the left and right subtrees
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        return root

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

# Helper function to create a binary tree
def newNode(val):
    return TreeNode(val)

if __name__ == "__main__":
    # Creating a binary tree
    root = newNode(1)
    root.left = newNode(2)
    root.right = newNode(3)
    root.left.left = newNode(4)
    root.left.right = newNode(5)
    root.right.left = newNode(6)
    root.right.right = newNode(7)
    
    print("Original tree: ", end="")
    printLevelOrder(root)
    
    solution = Solution()
    invertedRoot = solution.invertTree(root)
    
    print("Inverted tree: ", end="")
    printLevelOrder(invertedRoot)
