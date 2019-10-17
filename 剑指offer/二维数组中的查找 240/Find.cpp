// 10ms O(m + log n)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if( m == 0 ) return false;
        int n = array[0].size();
        if( n == 0 ) return false;
        if( target < array[0][0] || target > array[m-1][n-1] ) return false;
        
        for(int row = 0; row < m; row++){
            if( target == array[row][n-1] ) return true;
            else if( target > array[row][n-1] || target < array[row][0] ) continue;
            else{// 可能在这一行存在，进行二分查找
                int colMin = 0, colMax = n-1;
                while( colMin <= colMax ){
                    int colMid = colMin + (colMax - colMin)/2;
                    if( target == array[row][colMid] ) return true;
                    else if( target > array[row][colMid] ) colMin = colMid + 1;
                    else colMax = colMid - 1;
                }
            }
        }
        return false;
    }
};