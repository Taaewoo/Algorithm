# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        cur = head
        pre_node = ListNode()
        pre_node.next = head
        
        if cur:
            if cur.next:
                head = cur.next
        
        while True:
            if not cur:
                break
            if not cur.next:
                break
            
            nn_node = cur.next.next
            pre_node.next = cur.next
            cur.next.next = cur    
            cur.next = nn_node
            pre_node = cur
            cur = nn_node
                
        return head
        
             
                