# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    first, last = ListNode(), ListNode()
    
    def checkReverse(self,cur,k):
        check = True
        for i in range(0,k):
            if cur == None:
                check = False
                break
            cur = cur.next
            
        return (check, cur)
    
    def dfs(self,cur,k,idx):
        if idx == k:
            self.last = cur
            return cur
        
        reverseNode = self.dfs(cur.next,k,idx+1)
        reverseNode.next = cur
        
        if idx == 1:
            self.first = cur
        
        return cur
        
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        cur, pre = head, self
        
        while True:
            check, nxt = self.checkReverse(cur,k)
            print(check,nxt)
            if not check:
                break
                
            self.dfs(cur,k,1)
            
            pre.next = self.last
            self.first.next = nxt
            cur = nxt
            pre = self.first
            
        return self.next
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        