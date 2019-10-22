// 运行时间：4ms 占用内存：376k
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    	//输入有序，用对撞指针，第一次遇到就返回，此时两个数乘积最小（两个数越接近乘积越大）
        int p = 0, q = array.size()-1;
        vector<int> res;
        while( p < q ){
            int curSum = array[p] + array[q];
            if( curSum == sum ){
                res.push_back( array[p] );
                res.push_back( array[q] );
                return res;
            }
            else if( curSum < sum ) p++;
            else q--;
        }
        return res;
    }
};