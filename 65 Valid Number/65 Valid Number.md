Validate if a given string is numeric.

Some examples:

	"0" => true
	" 0.1 " => true
	"abc" => false
	"1 a" => false
	"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

**Hard!**

## Brutal force: test all possible conditions

It is super trivial and easy to make mistakes.  
Firstly, I thought it tests trivial conditions but then I notice that the conditions are too trivial and there is a more elegant solution:

## Solution: Finite state machine ! (elegant)

This blog is specific: http://blog.csdn.net/u012601587/article/details/50560838 

