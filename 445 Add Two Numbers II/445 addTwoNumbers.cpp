// 24 ms, faster than 74.18% 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, *cur2 = l2;
        stack<int> s1, s2;
        while( cur1 ){
            s1.push( cur1->val );
            cur1 = cur1->next;
        }
        while( cur2 ){
            s2.push( cur2->val );
            cur2 = cur2->next;
        }
        stack<ListNode*> s3;
        int rest = 0;
        while( !s1.empty() && !s2.empty() ){
            int l = s1.top(), r = s2.top();
            s1.pop(), s2.pop();
            int sum = l + r + rest;
            rest = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            s3.push(newNode);
        }
        stack<int> s4;
        !s1.empty() ? s4 = s1 : s4 = s2; 
        while( !s4.empty() ){
            int num = s4.top();
            s4.pop();
            int sum = num + rest;
            rest = sum/10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            s3.push(newNode);
        }
        if( rest != 0 ){
            ListNode* newNode = new ListNode(rest);
            s3.push(newNode);
        }
        ListNode* dummyHead = new ListNode(0);// by default dummyHead->next = NULL
        ListNode* pre = dummyHead, *cur = NULL;
        while( !s3.empty() ){
            cur = s3.top();
            s3.pop();
            pre->next = cur;
            pre = cur;
        }
        return dummyHead->next;
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