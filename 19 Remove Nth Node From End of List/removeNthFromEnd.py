# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        dummyHead = ListNode(0)
        dummyHead.next = head
        p = dummyHead
        q = p
        
        for i in range(n+1):
            q = q.next
            
        while q != None:
            p = p.next
            q = q.next
            
        delNode = p.next
        p.next = delNode.next
        del delNode
        
        retNode = dummyHead.next
        del dummyHead
        return retNode