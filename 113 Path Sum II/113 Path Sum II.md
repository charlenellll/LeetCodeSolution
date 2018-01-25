Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

	[
	   [5,4,11,2],
	   [5,8,4,5]
	]

## like path sum I + record different paths by a vector using push_back() and pop_back

### The hard part about this problem is how to optimize it

The first solution in the code file is the solution I used for linkedIn Machine Learning and Relevance Engineer Intern first round technical interview.   
The interviewer said I could optimize it but I didn't see how.

### Result:

After reading different kinds of code on the Internet, I think I found the optimization of the last few lines of code in my code. See the code file for the third solution.  
Because the interviewer reminded me nultiple times that maybe the order of my code can be changed and to be more concise, I think the third solution is the optimization he asked for. My code after optimization is the first one in the code file.