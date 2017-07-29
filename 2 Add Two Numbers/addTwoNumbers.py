# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None and l2 == None:
            return None
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        
        cur1 = l1
        cur2 = l2
        dummyHead = ListNode(0)
        cur = dummyHead
        
        rest = 0
        while cur1 != None and cur2 != None:
            
            next_one = ListNode(0)
            sum_res = cur1.val + cur2.val + rest
            rest = sum_res / 10
            next_one.val = sum_res % 10
            next_one.next = None
            
            cur.next = next_one
            cur = cur.next
            cur1 = cur1.next
            cur2 = cur2.next
            
        while cur1 != None or cur2 != None:
            
            if cur1 != None:
                
                next_one = ListNode(0)
                next_one.val = (cur1.val + rest) % 10
                next_one.next = None
                rest = (cur1.val + rest) / 10
                
                cur.next = next_one
                cur = cur.next
                cur1 = cur1.next
                
            else:
                next_one = ListNode(0)
                next_one.val = (cur2.val + rest) % 10
                next_one.next = None
                rest = (cur2.val + rest) / 10
                
                cur.next = next_one
                cur = cur.next
                cur2 = cur2.next
        
        if rest != 0:
            
            next_one = ListNode(0)
            next_one.val = rest % 10;
            rest = rest / 10;
            next_one.next = None;
            
            cur.next = next_one
            cur = cur.next
            
        retNode = dummyHead.next
        dummyHead.next = None
        return retNode
        