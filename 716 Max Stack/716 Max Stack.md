Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:

	MaxStack stack = new MaxStack();
	stack.push(5); 
	stack.push(1);
	stack.push(5);
	stack.top(); -> 5
	stack.popMax(); -> 5
	stack.top(); -> 1
	stack.peekMax(); -> 5
	stack.pop(); -> 1
	stack.top(); -> 5

Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.

## 2 stacks: one normal + one stores max values

// the names of stacks I use are s and maxs

the idea is mostly same as 155 min stack.  

The most different part is the popMax():
+ When the max value is not at the top of the normal stack s, we have to find it, pop it out, and put everything back in order
+ so we need a helper new stack to do that
+ one more thing we should pay attention:
	+ when we push back all elements in temp stack to s, we should update maxs synchronously (don't forget it! )
	+ so we use push() function we wrote, instead of just using s.push()

If we don't use the push() function we wrote to update maxs at the same time as s, such errors will occur:

	Output:
	["MaxStack","push","push","popMax","peekMax"]
	[[],[5],[1],[],[]]