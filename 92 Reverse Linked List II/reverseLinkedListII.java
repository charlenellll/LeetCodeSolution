/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        
        if( m == n )
            return head;
        
        int index = 1;
        ListNode cur = head;
        ListNode pre = null;
        ListNode next;
        
        while( cur != null ){
            if( index == m )
                break;
            pre = cur;
            cur = cur.next;
            index++;
        }
        ListNode head_point = pre;
        ListNode back_point = cur;
        
        pre = null;
        for(int i = 0; i < n-m+1; i++){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        
        if( head_point != null )
            head_point.next = pre;
        else
            head = pre;
        
        back_point.next = cur;
        
        return head;
    }
}