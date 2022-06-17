# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = cur = ListNode()
        carry = 0
        
        while not(l1 == None and l2 == None and carry == 0):
            l1Val = l1.val if l1 != None else 0
            l2Val = l2.val if l2 != None else 0
            
            add_val = l1Val + l2Val + carry
            carry = int(add_val/10)
            
            cur.next = ListNode(add_val%10)
            cur = cur.next
            
            if l1 != None: l1 = l1.next
            if l2 != None: l2 = l2.next 
        
        return res.next
