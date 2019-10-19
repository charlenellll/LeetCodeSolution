// 运行时间：4ms 占用内存：480k
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while( pHead1 && pHead2 ){
            if( pHead1->val < pHead2->val ){
                cur->next = pHead1;
                cur = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                cur->next = pHead2;
                cur = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if( pHead1 ) cur->next = pHead1;
        else if( pHead2 ) cur->next = pHead2;
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
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