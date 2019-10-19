// 运行时间：3ms 占用内存：604k O(N^2)
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 从后往前对偶数进行insertion sort
        int n = array.size();
        for(int evenIndex = n-1; evenIndex >= 0 ; evenIndex--){
            if( array[evenIndex] % 2 == 0 ){// 类似insertion sort操作
                int curNum = array[evenIndex];
                int i = evenIndex;
                while( i < n-1 && array[i + 1] % 2 == 1 )
                    array[i++] = array[i+1];
                array[i] = curNum;
            }
        }
    }
};

// 1 2 3 4 5 -> 1 3 5 2 4