// O(NlogN) time O(1) space
// 运行时间：4ms 占用内存：472k
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        sort( data.begin(), data.end() );
        bool flag1 = false, flag2 = false;
        for(int i = 0; i < data.size(); i++ ){
            if( i < data.size()-1 && data[i+1] == data[i] ){
                i++;
                continue;//i直接移两个
            }
            else{
                if( !flag1 ){
                    *num1 = data[i];
                    flag1 = true;
                }
                else if( !flag2 ){
                    *num2 = data[i];
                    return;
                }
            }
        }
    }
};