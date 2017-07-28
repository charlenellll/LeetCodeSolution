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
        
        ListNode cur = head;
        ListNode pre = null;
        while( cur != null ){
            if( record.contains(cur.val) ){
                pre.next = cur.next;
                cur = cur.next;
            }
            else{
                record.add(cur.val);
                pre = cur;
                cur = cur.next;
            }
        }
        return head;
    }
}