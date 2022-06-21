class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        res = cur = ListNode()
        
        while(list1 != None and list2 != None):
            if list1.val > list2.val:
                cur.next = list2
                cur, list2 = list2, list2.next
                
            else:
                cur.next = list1
                cur, list1 = list1, list1.next
        
        cur.next = list2 if list1 == None else list1
        
        return res.next
