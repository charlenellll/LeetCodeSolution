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
        cur = head
        pre = None
        while cur != None:
            if cur.val in record:
                pre.next = cur.next
                cur = cur.next
            else:
                record.add(cur.val)
                pre = cur
                cur = cur.next
        return head