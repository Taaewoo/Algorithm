# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:    
        cur = head
        prior = head
        
        cnt = 1
        while cur.next!=None:
            cur = cur.next
            cnt += 1
        
        n = cnt - n
        cur = head
        
        if cnt == 1:
            return None
        
        if n == 0:
            return head.next
        
        for i in range(0,n+1):
            if i==n-1:
                prior = cur
            if i==n:
                prior.next = cur.next
                break
            cur = cur.next
            
        return head