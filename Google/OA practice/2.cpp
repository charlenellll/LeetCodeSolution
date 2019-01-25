#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(vector<int>& s) {
        int l = 0, r = -1;
        unordered_map<int, int> type;
        int maxNum = 0;
        while( r+1 < s.size()){
            r++;
            type[s[r]]++;
            while( type.size() > 2 ){
                type[s[l]]--;
                if( type[s[l]] == 0) type.erase(s[l]);
                l++;
            }
            maxNum = max(maxNum, r-l+1);
        }
        return maxNum;
    }
};

int main() {
    Solution s;
//    int inputs[] = {1,2,1,3,4,3,5,1,2};
    int inputs[] = {1,2,1,2,1,2,1};
    vector<int> fruits(inputs, inputs+7);
    int res = s.lengthOfLongestSubstringTwoDistinct(fruits);
    cout << res;

//    // 这个地方很奇怪的是 -1 < vector.size()判断为错，而0就可以
//    // 原因在于！！size()的返回值是unsigned类型的，所以不能和负数比较大小！！
//    cout << (0 < fruits.size());
//    cout << (fruits.size() > -1);
    return 0;
}

// 可以把map换成int数组
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0, r = -1;
        int type[256] = {0};
        int typeCnt = 0;
        int maxNum = 0;
        while( r+1 < s.length()){
            r++;
            if( type[s[r]] == 0 ) typeCnt++;
            type[s[r]]++;
            while( typeCnt > 2 ){
                type[s[l]]--;
                if( type[s[l]] == 0) typeCnt--;
                l++;
            }
            maxNum = max(maxNum, r-l+1);
        }
        return maxNum;
    }
};