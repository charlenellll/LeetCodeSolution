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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if( head == NULL || k == 0 )
            return head;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        ListNode* q = p;
        
        int length = 0;
        for( int i = 0; i < k; i++ ){
            q = q->next;
            length ++;
            if( q->next == NULL )
                break;
        }
        if( q->next == NULL )
            k = k % length;
        
        q = p;
        for( int i = 0; i < k; i++)
            q = q->next;
        
        while( q-> next != NULL ){
            p = p->next;
            q = q->next;
        }

        q->next = dummyHead->next;
        dummyHead->next = p->next;
        p->next = NULL;
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};