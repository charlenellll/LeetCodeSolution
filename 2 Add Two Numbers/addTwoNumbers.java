/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        if( l1 == null && l2 == null )
            return null;
        if( l1 == null )
            return l2;
        if( l2 == null )
            return l1;
        
        ListNode cur1 = l1;
        ListNode cur2 = l2;
        ListNode dummyHead = new ListNode(0);
        ListNode cur = dummyHead;
        
        int rest = 0;
        while( cur1 != null && cur2 != null ){
            
            ListNode next = new ListNode(0);
            int sum = cur1.val + cur2.val + rest;
            rest = sum / 10;
            next.val = sum % 10;
            next.next = null;
            
            cur.next = next;
            cur = cur.next;
            cur1 = cur1.next;
            cur2 = cur2.next;
        }
        
        while( cur1 != null || cur2 != null ){
            
            if( cur1 != null ){
                
                ListNode next = new ListNode(0);
                next.val = ( cur1.val + rest ) % 10;
                rest = (cur1.val + rest) / 10;
                next.next = null;
                
                cur.next = next;
                cur = cur.next;
                cur1 = cur1.next;
            }
            else{
                
                ListNode next = new ListNode(0);
                next.val = ( cur2.val + rest ) % 10;
                rest = (cur2.val + rest) / 10;
                next.next = null;
                
                cur.next = next;
                cur = cur.next;
                cur2 = cur2.next;
            }
        }
        
        if( rest != 0 ){
            ListNode next = new ListNode(0);
            next.val = rest % 10;
            next.next = null;
            rest /= 10;
            cur.next = next;
            cur = cur.next;
        }
        
        ListNode retNode = dummyHead.next;
        dummyHead.next = null;
        return retNode;
    }
}