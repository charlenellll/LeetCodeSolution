// 运行时间：3ms 占用内存：488k
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead, *cur = head;//pre指向前面已规整链的最后一个元素
        while( cur ){
            if( cur->next && cur->next->val == cur->val ){//cur为重复元素的第一个
                int val = cur->val;
                while( cur && cur->val == val ) cur = cur->next;//cur移动到重复元素后
                pre->next = cur;//不更新pre，因为不知道新cur是不是重复的
            }
            else{//cur为不重复元素
                pre = cur;
                cur = cur->next;
            }
        }
        return dummyHead->next;
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