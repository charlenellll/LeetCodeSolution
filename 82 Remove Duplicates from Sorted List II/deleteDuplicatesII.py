# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        record = set()
        
        dummyHead = ListNode(0)
        dummyHead.next = head
        cur = dummyHead
        
        while cur.next != None:
            
            if cur.next.val not in record:
                pre = cur
            
            flag = 0
            while cur.next != None and cur.next.val in record:
                
                delNode = cur.next
                cur.next = delNode.next
                delNode.next = None
                flag = 1
                
            if flag == 1:
                
                delNode = cur
                pre.next = delNode.next
                cur = pre
                delNode.next = None
                
            if cur.next == None:
                break
                
            record.add(cur.next.val)
            cur = cur.next
        
        retNode = dummyHead.next
        dummyHead.next = None
        
        return retNode