/// Solution 2: O(N) time O(1) space
// 运行时间：4ms 占用内存：504k
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0; i < length; i++ ){
            if( numbers[i] == i ) // 当前数字位置正确
                continue;
            else{// 当前数字位置不对，将它放到对应的index上，顺便判断重复
                int curNum = numbers[i];
                if( numbers[curNum] == curNum ){
                    *duplication = curNum;
                    return true;
                }
                else swap( numbers[curNum], numbers[i--] );//i--对应for循环里的i++防止i跳走
            }
        }
        return false;
    }
};

// Solution 1: O(N^2) time when in worst condition,O(1) space
// 运行时间：3ms 占用内存：468k
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0; i < length; i++ )
            if( count(numbers, numbers + length, numbers[i]) > 1 ){
                *duplication = numbers[i];
                return true;
            }
        return false;
    }
};

// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false