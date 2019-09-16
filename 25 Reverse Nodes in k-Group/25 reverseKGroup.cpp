// 20 ms, faster than 70.51%
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* pre = dummyHead, *cur = head;
        while( cur ){
            int cnt = 0;
            ListNode* q = cur, *tail = cur;
            while( q ){ // the node after k nodes (including cur) from cur
                cnt++;
                q = q->next;
                if( cnt == k ) break;
            }
            if( cnt < k ) break;
            // do reverse
            cnt = 0;
            ListNode* p = pre;
            while( cnt < k ){
                ListNode* next = cur->next;
                cur->next = p;
                p = cur;
                cur = next;
                cnt++;
            }
            pre->next = p;
            tail->next = cur;
            pre = tail;
            tail = cur;
        }
        return dummyHead->next != NULL ? dummyHead->next : head; // A judgement is needed here in case k is larger than length
    }
};