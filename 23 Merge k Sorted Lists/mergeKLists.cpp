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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if( n == 0 ) return NULL;
        if( n == 1 ) return lists[0];
        return merge(lists, 0, n-1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if( left == right ) return lists[left];
        int mid = left + (right - left)/2;
        ListNode* leftpart = merge(lists, left, mid);
        ListNode* rightpart = merge(lists, mid+1, right);
        return mergeTwo(leftpart, rightpart);
    }
    
    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;
        while( l1 && l2 ){
            if( l1->val <= l2->val){
                head->next = l1;
                head = head->next;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                head = head->next;
                l2 = l2->next;
            }
        }
        
        if( l1 )
            head->next = l1;
        if( l2 )
            head->next = l2;
        
        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};