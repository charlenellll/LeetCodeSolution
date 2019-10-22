// 运行时间：4ms 占用内存：500k
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {//因为连续，因此维持一个窗口保持和为sum即可
        vector<vector<int>> res;
        if( sum <= 1 ) return res;
        int small = 1, big = 0, curSum = 0;//sum表示[small,big]闭区间窗口内的和
        while( small < (sum+1)/2 ){
            while( big <= (sum+1)/2 && curSum < sum ){
                big++;
                curSum += big;
            }// 出循环时 big >= sum/2 || curSum >= sum
            if( curSum == sum ){
                vector<int> curPath;
                for(int i = small; i <= big; i++)
                    curPath.push_back( i );
                res.push_back( curPath );
                curSum -= small;
                small++;
            }
            else{//吐出左边的小数：curSum > sum || 右边big已经移到头了（big >= sum/2）
                curSum -= small;
                small++;
            }
        }
        return res;
    }
};