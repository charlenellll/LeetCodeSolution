Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

# Solution - important, it is way more than an "easy" question

There're some important techniques used in this problem.

For the follow up requirement of O(N) Time and O(1) Space, we should use:


## Find the half position of a singly linked list 查找单链表的中点

Use a fast pointer and a slow pointer.

	LinkNode *FindMid(LinkNode *p){  
	        if(p == NULL){  
	                return NULL;  
	        }  
	        LinkNode *fast = p;  
	        LinkNode *slow = p;  
	        while(fast && fast->next){  
	                fast = fast->next->next;  
	                slow = slow->next;  
	        }  
	        return slow;  
	}  

此时slow指向前一半的最后一个元素。这里需要根据我们的需要对slow进行一些调整，比如： 

当链表元素为奇数个时，如果我们需要将slow指向后一半第一个元素，需要添加判断：

	if( fast ) slow = slow->next;

当单链表元素为偶数个时，将slow指向后一半的开头。

## Reverse the singly linked list

Reverse the second half of the singly linked list: see 206 Reverse Linked List.

# Optimization

可以再查找单链表中点的过程中完成前一半链表的reverse！

See the optimization code. It really needs delicate observation of pointers! 

Be aware of the relationships and positions of pointers, thinking clearly to avoid mistakes!