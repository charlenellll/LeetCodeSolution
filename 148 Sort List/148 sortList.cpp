// Solution 2: Bottom up
//--TODO

// Solution 1: Recursion
// 48 ms, faster than 57.78%

class Solution {
private:
    ListNode* cut(ListNode* head){ //返回中间指针靠左的那个
        ListNode* slow = head, *fast = head;
        while( fast->next && fast->next->next ){ // remember to judge fast->next
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) { //MergeSort from bottom up
        if( !head || !head->next ) return head; //ensure at least 2 elements
        ListNode* mid = cut(head);
        ListNode* midNext = mid->next;
        mid->next = NULL; // only leave the left part
        ListNode* newHead = sortList( head );
        ListNode* newMid = sortList( midNext );
        // merge them
        ListNode* p = newHead, *q = newMid;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while( p && q ){
            if( p->val < q->val ){
                cur->next = p;
                p = p->next;
            }
            else{
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        if( p != NULL ) cur->next = p;
        if( q != NULL ) cur->next = q;
        return dummyHead->next;
    }
};