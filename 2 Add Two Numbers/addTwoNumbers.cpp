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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        int rest = 0;

        while( cur1 != NULL && cur2 != NULL ){

            ListNode* next = new ListNode(0);
            int sum = cur1->val + cur2->val + rest;
            rest = sum / 10;
            next->val = sum % 10;
            next->next = NULL;

            cur->next = next;

            cur = cur->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        while( cur1 != NULL || cur2 != NULL){

            if( cur1 == NULL ){
                ListNode* next = new ListNode(0);
                next->val = (cur2->val + rest) % 10;
                rest = (cur2->val + rest) / 10;
                next->next = NULL;
                cur->next = next;
                cur = cur->next;
                cur2 = cur2->next;
            }
            else if( cur2 == NULL ){
                ListNode* next = new ListNode(0);
                next->val = (cur1->val + rest) % 10;
                rest = (cur1->val + rest) / 10;
                next->next = NULL;
                cur->next = next;
                cur = cur->next;
                cur1 = cur1->next;
            }
        }

        if( rest != 0){
            ListNode* next = new ListNode(0);
            next->val = rest % 10;
            rest /= 10;
            next->next = NULL;
            cur->next = next;
            cur = cur->next;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};