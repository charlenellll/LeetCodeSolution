// Solution 2: O(1) space
// 运行时间：3ms 占用内存：456k
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

// Solution 1: O(n) space
// 运行时间：3ms 占用内存：476k
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p = pHead1, *q = pHead2;
        unordered_set<ListNode*> list1;
        while( p ){
            list1.insert(p);
            p = p->next;
        }
        while( q ){
            if( list1.find(q) != list1.end() ) return q;
            q = q->next;
        }
        return nullptr;
    }
};

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/