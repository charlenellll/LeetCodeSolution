// 44 ms, faster than 95.14%
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA, *q = headB;
        while( p != q ){
            if( !p ) p = headB;//不能判断为!p->next因为这样没法处理无交点的情况，无交点时实际上二者交点在null
            else p = p->next;
            if( !q ) q = headA;
            else q = q->next;
        }
        return p; //(p == q) ? p : nullptr;
    }
};

// more concise
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*p = headA, *q = headB;
        while( p != q ){
            p = ( !p ) ? headB: p->next;
            q = ( !q ) ? headA: q->next;
        }
        return p; //(p == q) ? p : nullptr;
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