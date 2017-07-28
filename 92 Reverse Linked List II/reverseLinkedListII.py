# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m == n:
            return head
        
        index = 1
        pre = None
        cur = head
        
        while cur != None:
            if index == m:
                break
            pre = cur
            cur = cur.next
            index += 1
            
        head_point = pre
        back_point = cur
        
        pre = None
        for i in range(0, n-m+1):
            next_one = cur.next
            cur.next = pre
            pre = cur
            cur = next_one
            
        if head_point != None:
            head_point.next = pre
        else:
            head = pre
            
        back_point.next = cur
        
        return head
        
        