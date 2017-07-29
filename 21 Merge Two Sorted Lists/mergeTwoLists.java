/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
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
        
        while( cur1 != null || cur2 != null ){
            
            if( cur1 == null && cur2 != null){
                
                ListNode nextOne = new ListNode(0);
                nextOne.val = cur2.val;
                nextOne.next = null;
                cur.next = nextOne;
                cur = cur.next;
                cur2 = cur2.next;
            }
            if( cur2 == null && cur1 != null){
                
                ListNode nextOne = new ListNode(0);
                nextOne.val = cur1.val;
                nextOne.next = null;
                cur.next = nextOne;
                cur = cur.next;
                cur1 = cur1.next;
            }
            if( cur1 != null && cur2 != null && cur1.val < cur2.val ){
                ListNode nextOne = new ListNode(0);
                nextOne.val = cur1.val;
                nextOne.next = null;
                cur.next = nextOne;
                cur = cur.next;
                cur1 = cur1.next;
                continue;
            }
            else if( cur1 != null && cur2 != null && cur1.val >= cur2.val ){
                ListNode nextOne = new ListNode(0);
                nextOne.val = cur2.val;
                nextOne.next = null;
                cur.next = nextOne;
                cur = cur.next;
                cur2 = cur2.next;
                continue;
            }
        }
        
        ListNode retNode = dummyHead.next;
        dummyHead.next = null;
        return retNode;
    }
}