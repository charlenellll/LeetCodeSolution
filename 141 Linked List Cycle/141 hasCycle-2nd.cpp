// 12 ms, faster than 73.22% 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // if( !head ) return false; //not needed actually
        ListNode* slow = head, *fast = head;
        while( fast && fast->next ){ //judge fast here because fast can be null then is invalid to access fast->next
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast ) return true;
        }
        return false;
    }
};