/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        
        ListNode cur = dummyHead;
        while( cur.next != null ){
            
            if( cur.next.val == val ){
                ListNode delNode = cur.next;
                cur.next = delNode.next;
                delNode.next = null;
            }
            else
                cur = cur.next;
        }
        
        ListNode retNode = dummyHead.next;
        dummyHead.next = null;
        return retNode;
    }
}