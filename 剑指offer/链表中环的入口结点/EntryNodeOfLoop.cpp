// 运行时间：3ms 占用内存：464k
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head){
        if( !head || !head->next ) return nullptr;
        ListNode* slow = head->next, *fast = head->next->next;//slow和fast开始必须不一样才能入循环
        while( slow != fast ){
            if( !fast || !fast->next ) return nullptr; //无环
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h = head;
        while( h != slow ){
            h = h->next;
            slow = slow->next;
        }
        return h;
    }
};

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/