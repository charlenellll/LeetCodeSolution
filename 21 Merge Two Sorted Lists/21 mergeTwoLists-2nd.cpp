// 4 ms, faster than 98.92%

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1, *q = l2, *pre = dummyHead;
        while( p && q ){
            if( p->val <= q->val ){
                pre->next = p;
                pre = p;
                p = p->next;
            }
            else{
                pre->next = q;
                pre = q;
                q = q->next;
            }
        }
        ListNode* r = (p != NULL) ? p : q;
        pre->next = r; //link the rest to pre
        return dummyHead->next;
    }
};

// 8 ms, faster than 76.81%

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1, *q = l2, *pre = dummyHead;
        while( p && q ){
            if( p->val <= q->val ){
                pre->next = p;
                pre = p;
                p = p->next;
            }
            else{
                pre->next = q;
                pre = q;
                q = q->next;
            }
        }
        ListNode* r = (p != NULL) ? p : q;
        while( r ){ // But actually I don't need this. Just pre->next = r is fine!
            pre->next = r;
            pre = r;
            r = r->next;
        }
        return dummyHead->next;
    }
};