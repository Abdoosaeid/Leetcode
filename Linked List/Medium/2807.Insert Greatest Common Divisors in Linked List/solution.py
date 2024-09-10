from math import gcd
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head 
        while temp and temp.next :
            num1 = temp.val 
            num2 = temp.next.val 
            GCD = gcd(num1,num2)
            node = ListNode(GCD)
            node.next = temp.next
            temp.next = node
            temp = node.next

        return head    