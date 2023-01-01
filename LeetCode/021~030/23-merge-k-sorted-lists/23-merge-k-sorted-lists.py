# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head = ListNode()
        cur = ListNode()
        head = cur
        
        queue = []
    
        for l in lists:
            ln = l
            while ln:
                heapq.heappush(queue,ln.val)
                ln = ln.next
            
        while queue:
            tmp = ListNode(heapq.heappop(queue))
            cur.next = tmp
            cur = cur.next
            
        return head.next
        