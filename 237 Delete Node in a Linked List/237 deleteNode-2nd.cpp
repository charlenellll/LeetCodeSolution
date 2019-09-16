// Solution 2: delete this current node (re-value it as next node, then delete the next node)
// 8 ms, faster than 98.94% 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node->next;
        ListNode* next = cur->next;
        node->val = cur->val;
        node->next = next;
        delete cur;
    }
};

// Solution 1: Not suggested. Re-value the whole linked list -- NO NEED! :(
// 12 ms, faster than 80.35%
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         ListNode* pre;
//         while( node->next ){
//             ListNode* next = node->next;
//             node->val = next->val;
//             pre = node;
//             node = next;
//         }
//         pre->next = NULL;
//     }
// };