// Optimization: Finish the reverse of the first half of the linked list while we 找链表中点

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( !head || !head->next ) return true;
        ListNode* fast = head, *slow = head;
        ListNode* pre = NULL;
        ListNode* next;
        while( fast && fast->next ){
            next = slow->next;
            fast = fast->next->next;
            slow->next = pre;
            pre = slow;
            slow = next;  
        }
        // now pre is the head of the reversed first half, make fast the head of the second half
        // this needs delicate observation of pointers
        if( !fast ) fast = slow;
        else fast = slow->next;
        
        while( fast && pre ){
            if( fast->val != pre->val ) return false;
            fast = fast->next;
            pre = pre->next;
        }
        return true;
    }
};


// reverse the second half of the linked list
// 21 ms, 43.98%

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( !head || !head->next ) return true;
        ListNode* fast = head, *slow = head;
        while( fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow is the head of the second half of the input,当链表奇数个，slow为正中间，需要往后移一个
        if( fast ) slow = slow->next;
        
        slow = reverse(slow);
        
        while( head && slow ){
            if( head->val != slow->val ) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    // reverse the second half
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        // this procedure connects head and its orevious node, will not connect the next one with it
        // that's why head has to be the last one, instead of using [while(head->next)+return head]
        while(head){
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
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