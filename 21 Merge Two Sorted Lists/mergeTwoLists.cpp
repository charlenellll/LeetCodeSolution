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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if( l1 == NULL && l2 == NULL )
            return NULL;
        if( l1 == NULL )
            return l2;
        if( l2 == NULL )
            return l1;
        
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        
        while( cur1 != NULL || cur2 != NULL ){
            
            if( cur1 == NULL && cur2 != NULL ){
                ListNode* nextOne = new ListNode(0);
                nextOne->val = cur2->val;
                nextOne->next = NULL;
                cur->next = nextOne;
                cur = cur->next;
                cur2 = cur2->next;                
            }           
            if( cur2 == NULL && cur1 != NULL){
                ListNode* nextOne = new ListNode(0);
                nextOne->val = cur1->val;
                nextOne->next = NULL;
                cur->next = nextOne;
                cur = cur->next;
                cur1 = cur1->next;                
            }
            if( cur1 != NULL && cur2 != NULL && cur1->val < cur2->val ){
                ListNode* nextOne = new ListNode(0);
                nextOne->val = cur1->val;
                nextOne->next = NULL;
                cur->next = nextOne;
                cur = cur->next;
                cur1 = cur1->next;
                continue;
            }
            else if( cur1 != NULL && cur2 != NULL && cur1->val >= cur2->val ){
                ListNode* nextOne = new ListNode(0);
                nextOne->val = cur2->val;
                nextOne->next = NULL;
                cur->next = nextOne;
                cur = cur->next;
                cur2 = cur2->next;
                continue;                
            }
        }
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};