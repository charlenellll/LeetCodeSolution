Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

# O(N) way

The important part is following what rule do we update the max value?

Given by wikipedia:

	class Solution {  
	public:  
	    int maxSubArray(int A[], int n) {  
	        if (n == 0)  
	            return 0;  
	          
	        int max_ending_here = A[0];  
	        int max_so_far = A[0];  
	        for(int i = 1; i < n; ++i)  
	        {  
	            if (max_ending_here < 0)  
	                // So far we get negative values, this part has to be dropped  
	                max_ending_here = A[i];  
	            else  
	                // we can accept it, it could grow later  
	                max_ending_here += A[i];  
	                  
	            max_so_far = max(max_so_far, max_ending_here);  
	        }  
	        return max_so_far;  
	    }  
	};

# more Divide and conquer approach

sum(i) represent the maximum subarray starts from i，so the recursive equation would be:

sum(i) = max{A[i], A[i] + sum(i+1)}

// the sample 6ms solution used this thoughts

	int maxSubArray(int A[], int n) {
	  int sum = A[n - 1];
	  int maxSum = sum;

	  for (int i = n - 2; i >= 0; i--) {
	    sum = max(A[i], sum + A[i]);
	    maxSum = max(maxSum, sum);
	  }

	  return maxSum;
	}


## We cannot use collider pointers on an array containing negative elements!