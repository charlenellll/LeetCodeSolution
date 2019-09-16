// 0 ms, faster than 100.00%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {       //   | pre | cur, next | after |
        if( !head || !head->next ) return head;
        ListNode* dummyHead = new ListNode(0);
        ListNode* pre = dummyHead, *cur = head;
        while( cur && cur->next ){
            ListNode* next = cur->next;
            ListNode* after = next->next;
            pre->next = next;
            next->next = cur;
            cur->next = after;
            pre = cur; //已经转过来了，cur在next后面，所以pre=cur而不是next！
            cur = after;
        }
        return dummyHead->next;
    }
};