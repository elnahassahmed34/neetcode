class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        prev = None
        current = head

        while current is not None:
            next_node = current.next  # Store the next node
            current.next = prev       # Reverse the current node's pointer
            prev = current            # Move the previous node to current
            current = next_node       # Move to the next node

        return prev  # New head of the reversed list

# Helper function to create a linked list from a list
def create_list(nums):
    """
    Create a singly linked list from a list of values.

    :param nums: List of integers
    :return: ListNode, the head of the created linked list
    """
    dummy = ListNode()
    tail = dummy
    for num in nums:
        tail.next = ListNode(num)
        tail = tail.next
    return dummy.next

# Helper function to print a linked list
def print_list(head):
    """
    Print the values of a singly linked list.

    :param head: ListNode, the head of the singly linked list
    """
    current = head
    while current is not None:
        print(current.val, end=" ")
        current = current.next
    print()

# Main function to demonstrate the functionality
if __name__ == "__main__":
    solution = Solution()

    # Example 1
    nums1 = [0, 1, 2, 3]
    head1 = create_list(nums1)
    print("Original List 1:", end=" ")
    print_list(head1)

    reversed_head1 = solution.reverseList(head1)
    print("Reversed List 1:", end=" ")
    print_list(reversed_head1)

    # Example 2
    nums2 = []
    head2 = create_list(nums2)
    print("Original List 2:", end=" ")
    print_list(head2)

    reversed_head2 = solution.reverseList(head2)
    print("Reversed List 2:", end=" ")
    print_list(reversed_head2)
