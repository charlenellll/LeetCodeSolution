// 4 ms, faster than 98.96% 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head, *pre = dummyHead; // pre points to last distinct node
        while( cur && cur->next ){
            if( cur->val == cur->next->val ){ // duplicate
                int v = cur->val;
                while( cur && cur->val == v ){
                    cur = cur->next;
                } // when exit the loop : !cur || cur->val != v 
                pre->next = cur; // DO NOT DO "pre = cur;" HERE! cur is the next val & could be duplicate!
            }
            else{ // distinct
                pre = cur;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};