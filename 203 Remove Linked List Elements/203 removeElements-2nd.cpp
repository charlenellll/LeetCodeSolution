// 24 ms, faster than 94.69% 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head, *pre = dummyHead;
        while( cur ){
            ListNode* next = cur->next;
            if( cur->val == val ){
                pre->next = next;
                delete cur;
            }
            else
                pre = cur;
            cur = next;
        }
        return dummyHead->next;
    }
};