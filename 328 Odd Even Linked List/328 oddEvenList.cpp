// 16 ms, faster than 70.69%

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if( !head || !head->next ) return head;
        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0); // for even list
        oddHead->next = NULL, evenHead->next = NULL;
        int cnt = 0;
        ListNode* cur = head, *odd = oddHead, *even = evenHead;
        while(cur){
            cnt ++;
            if( cnt % 2 == 0 ){ // even
                even->next = cur;
                even = cur;
            }
            else{ // odd
                odd->next = cur;
                odd = cur;
            }
            cur = cur->next;
        }
        even->next = NULL; // This line is important! or answer will end in infinite loop!
        odd->next = evenHead->next;
        ListNode* retNode = oddHead->next;
        delete oddHead, evenHead;
        return retNode;
    }
};