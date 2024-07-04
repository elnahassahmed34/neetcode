# Definition for singly-linked list node
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head or not head.next:
            return False
        
        slow = head
        fast = head.next
        
        while fast != slow:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next
        
        return True

# Helper function to create a linked list with a cycle
def create_linked_list_with_cycle(values, index):
    if not values:
        return None
    
    # Create nodes
    nodes = [ListNode(val) for val in values]
    
    # Link nodes
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    
    # Create cycle if index is valid
    if index >= 0 and index < len(nodes):
        nodes[-1].next = nodes[index]
    
    return nodes[0] if nodes else None

# Main function to test the solution
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1: [1,2,3,4], index = 1 (cycle at index 1)
    values1 = [1, 2, 3, 4]
    index1 = 1
    head1 = create_linked_list_with_cycle(values1, index1)
    has_cycle1 = solution.hasCycle(head1)
    print(f"Example 1: {has_cycle1}")  # Output: True
    
    # Example 2: [1,2], index = -1 (no cycle)
    values2 = [1, 2]
    index2 = -1
    head2 = create_linked_list_with_cycle(values2, index2)
    has_cycle2 = solution.hasCycle(head2)
    print(f"Example 2: {has_cycle2}")  # Output: False
