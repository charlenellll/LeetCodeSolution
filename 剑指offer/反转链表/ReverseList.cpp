// 运行时间：4ms 占用内存：612k
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = NULL, *cur = pHead, *next = NULL;
        while( cur ){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
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