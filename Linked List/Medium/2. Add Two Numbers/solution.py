class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize a temporary ListNode to act as the head of the result list
        temp = ListNode()
        # Initialize a current pointer to traverse the result list
        cur = temp
        # Initialize carry to 0
        carry = 0
        
        # Iterate through the input lists or until there's a carry
        while l1 or l2 or carry:
            # Get the value of the current node in l1 or 0 if l1 is None
            v1 = l1.val if l1 else 0
            # Get the value of the current node in l2 or 0 if l2 is None
            v2 = l2.val if l2 else 0
            # Calculate the sum of the current digits along with carry
            value = carry + v1 + v2
            # Update carry for the next iteration
            carry = value // 10
            # Create a new ListNode with the digit value % 10
            cur.next = ListNode(value % 10)
            # Move to the next node in both input lists if they exist
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            # Move to the next node in the result list
            cur = cur.next
        
        # Return the next node after the initial dummy node, representing the actual result
        return temp.next
