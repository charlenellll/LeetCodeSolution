//2nd round
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = NULL, *cur = head;
        for(int i = 1; i < m; i++ ){
            pre = cur;
            cur = cur->next;
        }
        if( !cur->next ) return head;
        ListNode* before = pre, *tail = cur;
        pre = cur, cur = cur->next;
        for(int i = 0; i < n-m; i++ ){
            ListNode* after = cur->next;
            cur->next = pre;
            pre = cur;
            cur = after;
        }
        if(before) // Notice here! In some test cases m=1, before is NULL, then there is nothing before the new head, the new head is the tempHead of the middle reversed part.
            before->next = pre;
        else
            head = pre;
        tail->next = cur;
        return head;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(m == n)
            return head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next;
        int index = 1;
        
        // Point 1 : No need to use "next" in this loop
        while(cur != NULL){
             if( index == m )
                 break;
            pre = cur;
            cur = cur->next;
            index++;
        }
        ListNode* head_point = pre;
        ListNode* tail_point = cur;

        // Point 2: Important step! Set pre to NULL again.
        pre = NULL;
        for( int i = 0; i < n-m+1; i++){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // Point 3 & 4
        if(head_point != NULL)
            head_point->next = pre;
        else
            head = pre;
        
        tail_point->next = cur;
        
        return head;
    }
};

// I've made a few mistakes which are marked in the comments. Think about it thoroughly.
// Linked list and pointers can be a bit tricky