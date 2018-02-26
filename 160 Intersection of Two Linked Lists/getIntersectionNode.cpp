// 35 ms, beats 66.68%, it is the most common speed
// Optimization: don't judge the length of two linked list and move the pointers with so many if-statement
// the most efficient way is to make the two linked list of same length and then move the pointers without testing for the length!

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* start1 = headA, *start2 = headB;
        
        int countA = 0, countB = 0;
        while(start1) countA++, start1 = start1->next;
        while(start2) countB++, start2 = start2->next;
        
        start1 = headA, start2 = headB;
        while( countA > countB ) start1 = start1->next, countA--;
        while( countB > countA ) start2 = start2->next, countB--;
        
        // countA == countB
        while( start1 && start2 ){
            if( start1 == start2 ) return start1;
            start1 = start1->next, start2 = start2->next;
        }
        return NULL;
    }
};


// 40ms, 25.28%
// straight forward and not optimized

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* start1 = headA, *start2 = headB;
        
        int countA = 0, countB = 0;
        while(start1) countA++, start1 = start1->next;
        while(start2) countB++, start2 = start2->next;
        
        start1 = headA, start2 = headB;
        while( start1 && start2 ){
            if( start1 == start2 ) return start1;
            
            if( countA > countB ) start1 = start1->next, countA--;
            else if(countA == countB ) start1 = start1->next, start2 = start2->next, countA--, countB--;
            else start2 = start2->next, countB--;
        }
        return NULL;
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