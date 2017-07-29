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
    ListNode* deleteDuplicates(ListNode* head) {
        
        unordered_set<int> record;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        ListNode* pre;
        
        while( cur->next != NULL ){
            
            // Record the node before all duplicate nodes
            if( record.find(cur->next->val) == record.end() )
                pre = cur;
            
            int flag = 0;
            while( cur->next != NULL && record.find(cur->next->val) != record.end() ){
                
                // Delete the next node
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
                flag = 1;
            }
            
            // Delete the first node of the group of nodes with duplicate values, which is indicated by cur
            if(flag == 1){
                ListNode* delNode = cur;
                pre->next = cur->next;
                cur = pre;
                delete delNode;
            }
            
            if( cur->next == NULL )
                break;
            
            record.insert( cur->next->val );
            cur = cur->next;
        }
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};