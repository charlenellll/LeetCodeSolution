/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        if( head == null || k == 0 )
            return head;
        
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode p = dummyHead;
        ListNode q = p;
        
        int length = 0;
        for( int i = 0; i < k; i++){
            q = q.next;
            length++;
            if( q.next == null )
                break;
        }
        if( q.next == null )
            k = k % length;
        
        q = p;
        for( int i = 0; i < k; i++ )
            q = q.next;
        
        while( q.next != null ){
            p = p.next;
            q = q.next;
        }
        
        q.next = dummyHead.next;
        dummyHead.next = p.next;
        p.next = null;
        
        ListNode retNode = dummyHead.next;
        dummyHead.next = null;
        return retNode;
    }
}