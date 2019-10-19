// 运行时间：3ms 占用内存：476k
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p = pListHead, *q = p;
        for(int i = 0; i < k; i++ ){
            if( q ) q = q->next; 
            else return nullptr;//若k比链长？可按具体讨论处理
        }
        while( q ){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
// 1 2 3 4 5 k=2 指向4 距离NULL指针2步