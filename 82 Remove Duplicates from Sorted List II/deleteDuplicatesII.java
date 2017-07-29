/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        Set<Integer> record = new HashSet();
        
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode cur = dummyHead;
        ListNode pre = new ListNode(0);
        
        while( cur.next != null ){
            
            // Record the node before duplicates
            if( !record.contains( cur.next.val) )
                pre = cur;
            
            int flag = 0;
            // Remove all duplicate nodes except the first one
            while( cur.next != null && record.contains(cur.next.val) ){
                
                ListNode delNode = cur.next;
                cur.next = delNode.next;
                delNode.next = null;
                flag = 1;
            }
            
            // Remove the first node of all duplicate nodes
            if( flag == 1){
                
                ListNode delNode = cur;
                pre.next = cur.next;
                cur = pre;
                delNode.next = null;
            }
            if( cur.next == null )
                break;
            
            record.add(cur.next.val);
            cur = cur.next;
        }
        
        ListNode retNode = dummyHead.next;
        dummyHead.next = null;
        return retNode;
    }
}