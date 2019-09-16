// Solution 2: Put Inner loop into a function + cur is the node before断点（对cur->next进行插入排序）
// 16 ms, faster than 98.81%

class Solution {
private:
    void insert(ListNode* dummyHead, ListNode* node){ // Put inner loop into a function
        ListNode* pre = dummyHead, *cur = dummyHead->next;
        while( cur ){
            if( cur->val > node->val ){ //insert node before cur
                pre->next = node;
                node->next = cur;
                break;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if( !head || !head->next ) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head;// cur是在断点之前那个
        while( cur->next ){ //把cur->next放到合适的位置
            if( cur->next->val < cur->val ){// need to insert before cur
                ListNode* next = cur->next->next;
                insert(dummyHead, cur->next);
                cur->next = next;// 不能在此后面加cur=next！cur表示排好序的最后一个，而next显然是一个新的还没排序的
            }
            else
                cur = cur->next;
        }
        return dummyHead->next;
    }
};

// Solution 1: too slow, spend too much time to maintain bfCur
//  80 ms, faster than 7.19%

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if( !head || !head->next ) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head->next, *h, *pre, *bfCur = head;
        int index, cnt = 1; // position of cur
        while( cur ){
            h = dummyHead->next;
            pre = dummyHead;// the pointer before h, used for insertion before h
            index = 0; // position of h
            ListNode* next = cur->next;
            // insertion
            while( index < cnt ){
                if( h->val >= cur->val ){ //insert before h
                    pre->next = cur;
                    cur->next = h;
                    bfCur->next = next;
                    index++;
                    break;
                }
                else{ //continue searching
                    pre = h;
                    h = h->next;
                }
                index++;
            }
            // This part is important to maintain ---------
            while( index < cnt ) { 
                h = h->next;
                index++;
            }
            bfCur = h;
            // --------------------------------------------
            cur = next;
            cnt++;
        }
        return dummyHead->next;
    }
};