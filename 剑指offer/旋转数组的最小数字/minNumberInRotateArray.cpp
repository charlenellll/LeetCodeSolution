// 运行时间：28ms 占用内存：604k
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        for(int i = 0; i < rotateArray.size()-1; i++ ){
            if( rotateArray[i+1] < rotateArray[i] )
                return rotateArray[i+1];
        }
        return 0;
    }
};