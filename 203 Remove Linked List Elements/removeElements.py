# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        dummyHead.next = head
        
        cur = dummyHead
        while cur.next != None :
            
            if cur.next.val == val:
                delNode = cur.next
                cur.next = delNode.next
                delNode.next = None
            else:
                cur = cur.next
                
        retNode = dummyHead.next
        dummyHead.next = None
        return retNode