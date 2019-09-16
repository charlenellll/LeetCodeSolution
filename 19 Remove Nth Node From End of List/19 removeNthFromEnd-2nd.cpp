// 4 ms, faster than 85.73%

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { // q-p = n if q是tail后的空指针，p到q左边那个刚好n个
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = head, *q = head, *pre = dummyHead;
        for(int i = 0; i < n; i++ ) // n times
            q = q->next;
        while( q ){
            q = q->next;
            pre = p;
            p = p->next;
        }
        ListNode* next = p->next;
        pre->next = next;
        delete p;
        return dummyHead->next;
    }
};