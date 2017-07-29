# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        if node == None:
            return
        if node.next == None:
            node.next = None
            return
        
        node.val = node.next.val
        delNode = node.next
        node.next = delNode.next
        del delNode
        return