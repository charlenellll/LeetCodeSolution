// 0 ms, beats 100%

class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int,int> lengths; // max lengths on each level
        int isFile = 0, level = 0, curLen = 0, maxLen = 0, res = 0;
        
        for(int i = 0; i < input.size();i++){
            switch( input[i] ){
                case '\n': level = 0; isFile = 0; curLen = 0; break;
                case '\t': level++; break;
                case '.': isFile = 1; curLen++; break;
                default:
                    curLen++;
                    lengths[level] = curLen; // 每一级都是固定的，你并不能选最优组合，所以不要操心max
                    res = 0;
                    if( isFile ){
                        for( int i = 0; i <= level; i++ ) res += lengths[i];
                        maxLen = max(maxLen, res+level);
                    }
                    break;
            }
        }
        return maxLen;
    }
};