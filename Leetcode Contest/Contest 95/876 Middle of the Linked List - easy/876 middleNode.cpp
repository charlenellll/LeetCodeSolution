
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if( head == NULL ) return head;
        ListNode *slow = head, *fast = head;
        
        while( fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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