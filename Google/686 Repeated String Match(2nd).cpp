// 3. 再优化：如果B中含有A所没有的字母，B必然不能由repeatedA含有。
// 6 ms, 99.42%
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if( B.find_first_not_of(A) != B.npos ) return -1;
        int times = 1;
        string tempA = A;
        while(tempA.size() < B.size()){
            tempA += A;
            times += 1;
        }
        if( tempA.find(B) != string::npos ) return times;
        tempA += A;
        times ++;
        if( tempA.find(B) != string::npos ) return times;
        else return -1;
    }
};

// 2. 优化：我在判断A是否能包含B的判断用时太多，允许了别人加到10000，需要优化这个时间
// 难点：如何判断序列B不会在重复次A序列中出现。
// trick：如果B会出现，必定在A长度+B长度中出现，如果不，则不会找到的。可以这么想：B序列是重复次A序列的一片，如果目前刚刚和B序列等长或比B序列短一点的A序列中没有B， 则B在重复次A中被两端分开了，只要加上一个A或B，必然在其中。
// 18 ms, 75.09%
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int times = 1;
        string tempA = A;
        while(tempA.size() < B.size()){ // 先达到至少一样长
            tempA += A;
            times += 1;
        }
        if( tempA.find(B) != string::npos ) return times; // 如果在B或A的长度里符合，必须现在返回，否则后面times会被修改
        tempA += A;
        times ++;
        if( tempA.find(B) != string::npos ) return times; // 如果在A+B的长度里符合，现在返回
        else return -1;
    }
};

// 1. 初始，比较原始的解法：
// 如果B比A长，至少A要和B一样长；然后一个个加上A，看左边字符串是否包含B
// 540ms
// 13%

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int times = 1;
        string tempA = A;
        if( A.size() <= B.size() ) times = B.size() / A.size();
        for(int i = 1; i < times; i++ ){
            tempA += A;
        }
        while( tempA.find(B) == string::npos ){
            tempA += A;
            times ++;
            if( tempA.size() > 10000 )
                return -1;
        }
        return times;
    }
};