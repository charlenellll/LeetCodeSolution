# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None or k == 0:
            return head
        
        dummyHead = ListNode(0)
        dummyHead.next = head
        p = dummyHead
        q = p
        
        # I don't know why for-loop like in C++ or Java would meet Memory Error here, eventually while-loop works
        length = 0
        while length < k:
            q = q.next
            length += 1
            if q.next == None:
                break
                
        if q.next == None:
            k = k % length
        
        q = p
        for i in range(0,k):
            q = q.next
        
        while q.next != None:
            p = p.next
            q = q.next
        
        q.next = dummyHead.next
        dummyHead.next = p.next
        p.next = None
        
        retNode = dummyHead.next
        del dummyHead
        return retNode