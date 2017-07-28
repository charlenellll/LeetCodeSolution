/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        
        // No need for "new" right here
        ListNode pre = null;
        ListNode cur = head;
        
        while( cur != null ){
            
            ListNode next = cur.next;
            
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}