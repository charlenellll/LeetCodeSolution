// O(n) time O(1) space
// Runtime: 16 ms, faster than 97.55% 
// Memory Usage: 9.6 MB, less than 100.00% 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra = 0;
        ListNode* cur = l1, *p = l1, *q = l2, *pre = NULL;
        while( p != NULL || q != NULL ){
            if( !p && q ){
                pre->next = q;
                break;
            }
            else if( p && !q )
                break;
            int sum = p->val + q->val + extra;
            extra = sum / 10;
            sum %= 10;
            p->val = sum;
            pre = p;
            p = p->next;
            q = q->next;
        }
        if( extra > 0 ){
            while( pre->next ){
                ListNode* next = pre->next;
                next->val += extra;
                extra = next->val / 10;
                next->val %= 10;
                pre = next;
            }
            if( extra > 0 ){
                ListNode* newNode = new ListNode(extra);
                pre->next = newNode;
            }
        }
        return l1;
    }
};