# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        dummyHead = ListNode(0)
        dummyHead.next = head
        p = dummyHead
        
        while p.next != None and p.next.next != None:
            
            node1 = p.next
            node2 = node1.next
            nextOne = node2.next
            
            node2.next = node1
            node1.next = nextOne
            p.next = node2
            
            p = node1
            
        retNode = dummyHead.next
        dummyHead.next = None
        
        return retNode