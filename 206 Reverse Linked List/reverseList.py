# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # "None" is enough. If use ListNode(None), the result will be [None] instead of [] for input []
        pre = None
        cur = head
        
        while cur != None :
            next_one = cur.next
            
            cur.next = pre
            pre = cur
            cur = next_one
            
        return pre
        