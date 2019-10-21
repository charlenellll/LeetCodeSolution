// 运行时间：5ms 占用内存：496k
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> firstIndex(58, -1);// 记录字符首次出现的index，未出现为-1，多次出现为-2
        for(int i = 0; i < str.size(); i++ ){
            int curId = str[i] - 'A';
            if( firstIndex[curId] == -1 )
                firstIndex[curId] = i;
            else if( firstIndex[curId] >= 0 )
                firstIndex[curId] = -3;
        }
        sort( firstIndex.begin(), firstIndex.end());
        int k = 58;
        while( k >= 0 && firstIndex[k-1] >= 0 ) k--;
        return (k == 58) ? -1 : firstIndex[k]; //无解(全为负) or 非负的最小数
    }
};