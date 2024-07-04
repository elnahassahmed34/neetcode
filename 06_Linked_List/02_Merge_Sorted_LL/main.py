# Definition for singly-linked list node
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Function to merge two sorted linked lists
def mergeTwoLists(list1, list2):
    # Create a dummy node to serve as the head of the merged list
    dummy = ListNode()
    tail = dummy
    
    # Traverse both lists and append the smaller value node to the tail
    while list1 and list2:
        if list1.val < list2.val:
            tail.next = list1
            list1 = list1.next
        else:
            tail.next = list2
            list2 = list2.next
        tail = tail.next
    
    # Append the remaining nodes of list1 or list2
    tail.next = list1 or list2
    
    # Return the merged list starting from the next node of dummy
    return dummy.next

# Function to print the linked list
def printList(head):
    result = []
    current = head
    while current:
        result.append(current.val)
        current = current.next
    return result

# Helper function to create a linked list from a list of values
def createLinkedList(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

# Main function to test the solution
def main():
    # Create list1: 1 -> 2 -> 4
    list1 = createLinkedList([1, 2, 4])
    
    # Create list2: 1 -> 3 -> 5
    list2 = createLinkedList([1, 3, 5])
    
    # Merge the two lists
    mergedList = mergeTwoLists(list1, list2)
    
    # Print the merged list: [1, 1, 2, 3, 4, 5]
    print("Merged List:", printList(mergedList))

# Execute the main function
if __name__ == "__main__":
    main()
