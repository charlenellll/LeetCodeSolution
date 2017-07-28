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
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* delNode;
        while( cur!= NULL ){
            if( record.find(cur->val) != record.end() ){
                pre->next = cur->next;
                delNode = cur;
                cur = cur->next;
                delete delNode;
            }
            else{
                record.insert(cur->val);
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};