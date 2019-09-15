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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* pre = NULL;
        ListNode* cur = head;
        
        while( cur != NULL ){
            ListNode* next = cur->next;
            
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)


//2nd round:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while( head ){
            ListNode* nextNode = head->next;
            head->next = pre;
            // if( nextNode ) nextNode->next = head; // Wrong! I don't need to do this here! this is for next step！I only need to change one pointer in the linked list at one step!!
            pre = head;
            head = nextNode;
        }
        return pre;
    }
};