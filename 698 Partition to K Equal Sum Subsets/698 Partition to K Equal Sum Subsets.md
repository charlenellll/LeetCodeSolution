Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:  

	Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
	Output: True
	Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

# Solution

It looks similar to 416 except 416 was to divide it into two subsets.

## similar to Knapsack problem, solve it recursively

We want to get k knapsacks each of which has the total sum of values = sum/k:  
+ Do it recursively
+ Terminal condition:
	+ if k == 1 (if we has only one knapsack left, the other k-1 knapsacks have been filled up), return true of course
	+ if the sum of values in this knapsack == sum/k, this one's filled up so we can start to search for the next knapsack
	+ when the current sum in the knapsack > sum/k or all items in the array has been used but we haven't reached the target, return false

Some thoughts from internet: 

### Solution 1 

	这道题给了我们一个数组nums和一个数字k，问我们该数字能不能分成k个非空子集合，使得每个子集合的和相同。
	给了k的范围是[1,16]，而且数组中的数字都是正数。这跟之前那道Partition Equal Subset Sum很类似，但是那道题只让分成两个子集合，所以问题可以转换为是否存在和为整个数组和的一半的子集合，可以用dp来做。
	但是这道题让求k个和相同的，感觉无法用dp来做，因为就算找出了一个，其余的也需要验证。

	这道题我们可以用递归来做，首先我们还是求出数组的所有数字之和sum，首先判断sum是否能整除k，不能整除的话直接返回false。
	然后需要一个visited数组来记录哪些数组已经被选中了，然后调用递归函数，我们的目标是组k个子集合，是的每个子集合之和为target = sum/k。
	我们还需要变量start，表示从数组的某个位置开始查找，curSum为当前子集合之和，在递归函数中，如果k=1，说明此时只需要组一个子集合，那么当前的就是了，直接返回true。
	如果curSum等于target了，那么我们再次调用递归，此时传入k-1，start和curSum都重置为0，因为我们当前又找到了一个和为target的子集合，要开始继续找下一个。
	否则的话就从start开始遍历数组，如果当前数字已经访问过了则直接跳过，否则标记为已访问。然后调用递归函数，k保持不变，因为还在累加当前的子集合，start传入i+1，curSum传入curSum+nums[i]，因为要累加当前的数字，如果递归函数返回true了，则直接返回true。否则就将当前数字重置为未访问的状态继续遍历.

	class Solution {
	public:
	    bool canPartitionKSubsets(vector<int>& nums, int k) {
	        int sum = accumulate(nums.begin(), nums.end(), 0);
	        if (sum % k != 0) return false;
	        vector<bool> visited(nums.size(), false);
	        return helper(nums, k, sum / k, 0, 0, visited);
	    }
	    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
	        if (k == 1) return true;
	        if (curSum == target) return helper(nums, k - 1, target, 0, 0, visited);
	        for (int i = start; i < nums.size(); ++i) {
	            if (visited[i]) continue;
	            visited[i] = true;
	            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) return true;
	            visited[i] = false;
	        }
	        return false;
	    }
	};

### Solution 2

	下面这种方法也挺巧妙的，思路是建立长度为k的数组v，只有当v里面所有的数字都是target的时候，才能返回true。
	我们还需要给数组排个序，由于题目中限制了全是正数，所以数字累加只会增大不会减小，一旦累加超过了target，这个子集合是无法再变小的，所以就不能加入这个数。
	实际上相当于贪婪算法，由于题目中数组数字为正的限制，有解的话就可以用贪婪算法得到。
	我们用一个变量idx表示当前遍历的数字，排序后，我们从末尾大的数字开始累加，我们遍历数组v，当前位置加上nums[idx]，如果超过了target，我们掉过继续到下一个位置，否则就调用递归，此时的idx为idx-1，表示之前那个数字已经成功加入数组v了，我们尝试着加下一个数字。
	如果递归返回false了，我们就将nums[idx]从数组v中对应的位置减去，还原状态，然后继续下一个位置。
	如果某个递归中idx等于-1了，表明所有的数字已经遍历完了，此时我们检查数组v中k个数字是否都为target，是的话返回true，否则返回false。

	class Solution {
	public:
	    bool canPartitionKSubsets(vector<int>& nums, int k) {
	        int sum = accumulate(nums.begin(), nums.end(), 0);
	        if (sum % k != 0) return false;
	        vector<int> v(k, 0);
	        sort(nums.begin(), nums.end());
	        return helper(nums, sum / k, v, (int)nums.size() - 1);
	    }
	    bool helper(vector<int>& nums, int target, vector<int>& v, int idx) {
	        if (idx == -1) {
	            for (int t : v) {
	                if (t != target) return false;
	            }
	            return true;
	        }
	        int num = nums[idx];
	        for (int i = 0; i < v.size(); ++i) {
	            if (v[i] + num > target) continue;
	            v[i] += num;
	            if (helper(nums, target, v, idx - 1)) return true;
	            v[i] -= num;
	        }
	        return false;
	    }
	};
