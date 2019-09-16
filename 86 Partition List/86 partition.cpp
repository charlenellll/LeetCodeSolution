// My code is kind of complicated, should see sample code.
// Sample code:
// 8 ms, faster than 55.78% 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(!head || !head->next)
            return head;
     
        ListNode *before=new ListNode(0);
        ListNode *after=new ListNode(0);
        
        ListNode *b=before, *a=after;
        ListNode *temp=head;
        
        while(temp){
            if(temp->val<x){
                b->next=temp;
                b=b->next;
            }
            else{
                a->next=temp;
                a=a->next;
            }
            temp=temp->next;
        }
        //
        a->next=NULL;
        
        b->next=after->next;
        return before->next;
    }
};

// Solution 1
// 8 ms, faster than 55.78% 

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead, *cur = head, *bigTail; // pre->node before small part; cur->1st small element
        while( cur ){
            while( cur ){
                if( cur->val < x){
                    pre = cur;
                    cur = cur->next;
                }
                else
                    break;
            }
            while( cur ){
                if( cur->val >= x ){
                    bigTail = cur;
                    cur = cur->next;
                }
                else
                    break;
            }
            if( !cur ) // when everything is >= x or in order
                return dummyHead->next; // add these 2 lines makes my code work!The condition is not too complicated!
            ListNode* smallHead = cur, * smallTail; 
            while( cur ){
                if( cur->val < x ){
                    smallTail = cur;
                    cur = cur->next;
                }
                else
                    break;
            }
            ListNode* bigHead = pre->next;
            pre->next = smallHead;
            smallTail->next = bigHead;
            bigTail->next = cur;
            pre = smallTail;
        }
        return dummyHead->next;
    }
};