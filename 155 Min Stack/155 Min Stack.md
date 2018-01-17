
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:

	MinStack minStack = new MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.getMin();   --> Returns -3.
	minStack.pop();
	minStack.top();      --> Returns 0.
	minStack.getMin();   --> Returns -2

## 2 Stacks: one normal stack + one only stores min values

Wrong solution: 
I could use one int number to record the min value, but:
+ if I pop() it, I won't know the second smallest number, I have no way to trace back
+ since in Leetcode the input contains INT_MAX so I have no way to compare INT_MAX with INT_MAX  
so I should use another stack.

For the second stack: when I do the push(x) operation,  
+ only push a copy into minStack when x <= minStack.top()
+ at first, I only want to push in the minimum values, ignored x = current minValue. It will lead to error when there are multiple copies of min value been pushed into stack. So "=" is important