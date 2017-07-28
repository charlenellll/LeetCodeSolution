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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* cur = dummyHead;       
        while( cur->next != NULL ){
            
            if( cur->next->val == val ){
                // Delete cur->next
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
                // In many other languages we may not need to release the space by ourselves
                // All we have to do is set " delNode->next = NULL "
            }
            else
                cur = cur->next;
        }
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        
        return retNode;
    }
};