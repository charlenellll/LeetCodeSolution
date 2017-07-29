/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode p = dummyHead;
        ListNode q = p;
        
        for( int i = 0; i < n+1; i++)
            q = q.next;
        
        while( q != null ){
            p = p.next;
            q = q.next;
        }
        
        ListNode delNode = p.next;
        p.next = delNode.next;
        delNode.next = null;
        
        ListNode retNode = dummyHead.next;
        dummyHead.next = null;
        return retNode;
    }
}