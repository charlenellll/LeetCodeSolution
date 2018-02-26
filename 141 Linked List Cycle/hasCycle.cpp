// O(n) Time, no extra space
// Solution 2: fast and slow pointers
// 10ms, beats 29.58% but it is the same time as majority
// this code is more neat than the one below it

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while( fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow ) // change its place to this place
                return true;
        }
        return false;
    }
};

// 11ms
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( !head || !head->next ) return false;
        ListNode* fast = head, *slow = head;
        fast = fast->next->next, slow = slow->next;
        while( fast && fast->next ){
            // because I put it here, it will immediately give "false" when I entered the loop
            // with fast and slow both are head. It ends up I used some extra if statement at the head of this function
            // If I reorder the lines, I can get a neat solution without giving wrong answers. See above!
            if( fast == slow )
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};


// O(n) Time, O(n) space
// Solution 1: Basic: use a set to find out if the same object appears
// 24ms, beats 1.67%

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> record;
        while( head ){
            if(record.find(head) != record.end() )
                return true;
            else
                record.insert(head);
            head = head->next;
        }
        return false;
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