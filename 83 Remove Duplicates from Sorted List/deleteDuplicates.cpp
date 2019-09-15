// Solution 2 optimization: delete the actual nodes
// Runtime: 8 ms, faster than 97.57% 
// Memory Usage: 9.3 MB, less than 81.13% 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 由于单项链表，我们只能删除前面的重复值（只能知道next值，不能知道前一个值）
        if( !head ) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode*cur = head, *pre = dummyHead;
        while( cur->next ){
            ListNode* next = cur->next;
            if( next->val == cur->val ){
                pre->next = next;
                delete cur; // This line is important. It actually deletes this node.
            }
            else
                pre = cur;
            cur = next;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

// Solution 2: O(n) time O(1) space, it used the characteristics of a sorted list
// 2nd round practice
// Runtime: 12 ms, faster than 71.64% 
// Memory Usage: 9.2 MB, less than 90.57%

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 由于单项链表，我们只能删除前面的重复值（只能知道next值，不能知道前一个值）
        if( !head ) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode*cur = head, *pre = dummyHead;
        while( cur->next ){
            ListNode* next = cur->next;
            if( next->val == cur->val ){
                cur->next = NULL; // I should replace this with the code that actually delete this node
                pre->next = next;
            }
            else
                pre = cur;
            cur = next;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

// Solution 1: O(n) time O(n) space - waste too much!
// first round practice
// Runtime: 16 ms, faster than 10.85% 
// Memory Usage: 9.9 MB, less than 15.09%

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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */