Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

	Example 1:
	
	Input: [[1,1],2,[1,1]]
	Output: [1,1,2,1,1]
	Explanation: By calling next repeatedly until hasNext returns false, 
	             the order of elements returned by next should be: [1,1,2,1,1].
	Example 2:
	
	Input: [1,[4,[6]]]
	Output: [1,4,6]
	Explanation: By calling next repeatedly until hasNext returns false, 
	             the order of elements returned by next should be: [1,4,6].

## Queue

O(n) time for construction, O(n) space, O(1) time for next() function.

## Stack

The differences btw stack method and queue method is that the stack peeks and flattens elements at hasNext() time. (Remember to call hasNext() before next() internally to avoid exception)

O(nestedList.size()) time for construction, O(nestedList.size()) space, O(avg length of NestedInteger) time for hasNext() function.

This is iterative version of flatting the nested list:

+ In the constructor, we push all the nestedList into the stack from back to front, so when we pop the stack, it returns the very first element. 
+ In the hasNext() function, we peek the first element in stack currently, and if it is an Integer, we will return true and pop the element. If it is a list, we will further flatten it. 




```c++
	// stack version is more delicate
	// here's the sample code:
	class NestedIterator {
	public:
	    NestedIterator(vector<NestedInteger> &nestedList) {
	        begins.push(nestedList.begin());
	        ends.push(nestedList.end());
	    }

	    int next() {
	        hasNext();
	        return (begins.top()++)->getInteger();
	    }

	    bool hasNext() {
	        while (begins.size()) {
	            if (begins.top() == ends.top()) {
	                begins.pop();
	                ends.pop();
	            } else {
	                auto x = begins.top();
	                if (x->isInteger())
	                    return true;
	                begins.top()++;
	                begins.push(x->getList().begin());
	                ends.push(x->getList().end());
	            }
	        }
	        return false;
	    }

	private:
	    stack<vector<NestedInteger>::iterator> begins, ends;
	};
```
