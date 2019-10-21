// 运行时间：3ms 占用内存：480k
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {//问题分析角度：之前连续sequence之和(>=0才在当前累加，否则另起炉灶)+ 当前项
        int n = array.size();
        if( n < 1 ) return 0;
        int maxSum = INT_MIN, curSum = 0;
        for(int i = 0; i < n; i++ ){
            if( curSum < 0 )
                curSum = array[i];// 之前的和小于0，不如从当前开始
            else// 之前的和>=0，可以累加当前项
                curSum += array[i];
            maxSum = max(maxSum, curSum);//注意这里max在if-else之外！不论如何更新了curSum就要更新maxSum！
        }
        return maxSum;
    }
};