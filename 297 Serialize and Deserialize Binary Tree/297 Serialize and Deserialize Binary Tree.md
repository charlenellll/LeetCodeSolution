Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

	    1
	   / \
	  2   3
	     / \
	    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

## DFS + istringstream + stoi

Any way of serializing a tree is always successful, the hard part is deserializing it.  
Pass the string I get to deserialize():

### For the string input
Firstly I worte a version using BFS to get the string and deserializing it by the index relationship to construct a tree.  
Then I encountered a test case [-1, 0, 1] so the negative numbers broke the consistency of index relationship in my string (array of char's). 

The solution is istringstream:
+ #include<sstream>
+ istringstream will AUTOMATICALLY split the string by " ", each time output one character

### For converting string to number

I used to use (char) data-'0' but it won't work on '-1'.  
+ use stoi()
+ but before using it, you have to make sure the string represents a number so be careful about the if satement and filter out other conditions!


