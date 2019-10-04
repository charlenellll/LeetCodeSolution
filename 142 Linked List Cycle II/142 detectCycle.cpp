// Solution 2: O(1) space
// 8 ms, faster than 97.72% 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast ) break;
        }
        if( !fast || (fast && !fast->next) ) return nullptr; //记得判断没有环
        ListNode* h = head, *e = fast;
        while( h != e ){
            h = h->next;
            e = e->next;
        }
        return h;
    }
};

// Solution 1: O(n) space
// 20 ms, faster than 18.42%
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head, *pre = NULL;
        unordered_map<ListNode*, pair<ListNode*,int>> record;
        int idx = 0, fidx = 0;
        while( fast && fast->next && record.find(fast) == record.end() ){
            record[slow] = make_pair(pre, idx);//该key节点的上一个节点指针 + key节点在链中idx
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            idx++;
            fidx += 2;
        }
        if( !fast || (fast && !fast->next)) return NULL;
        // int numInCycle = fidx - record[fast].second;
        while( slow ){
            if( record.find(slow->next) != record.end() ) break;
            record[slow] = make_pair(pre, idx);
            pre = slow;
            slow = slow->next;
            idx++;
        }
        // int outCycle = idx - numInCycle + 1;
        if( (idx + 1) % 2 == 0 || fast->next == fast ) return fast; // outCycle + numInCycle
        else return record[fast].first;
    }
};