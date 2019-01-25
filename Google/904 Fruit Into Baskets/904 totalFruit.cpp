// OA-2 problem
// 1. a little slow: 144 ms, faster than 27.86% of C++ online submissions
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // sliding window
        int l = 0, r = -1;
        unordered_map<int,int> types;
        int count = 0, maxCount = 0;
        while( r+1 < tree.size() ){
            types[tree[++r]]++;
            count ++;
            while( types.size() > 2 ){
                types[tree[l]]--;
                if( types[tree[l]] == 0 ) types.erase(tree[l]);
                l++;
                count --;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

// 2. optimization: remove count operations. use r-l+1; still kind of slow: 136 ms, faster than 34.83%
class Solution {
public:
    int totalFruit(vector<int>& tree) { // sliding window
        int l = 0, r = -1;
        unordered_map<int,int> types;
        int maxCount = 0;
        while( r+1 < tree.size() ){
            types[tree[++r]]++;
            while( types.size() > 2 ){
                types[tree[l]]--;
                if( types[tree[l]] == 0 ) types.erase(tree[l]);
                l++;
            }
            maxCount = max(maxCount, r-l+1);
        }
        return maxCount;
    }
};

// 3. 用数组:很快但是很繁琐
// sample 96 ms, faster than 72.90%

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if (tree.size() <= 2) return tree.size();
        // kindA, kindB: the kind of fruit which is in our current basket (-1 represents none)
        // the last continuous segment of the same fruit
        
        int kindA = tree[0];
        int kindB = tree[1] != tree[0] ? tree[1] : -1;
        int currLen = 2;
        int maxLen = 2;
        int kindC = kindA == kindB ? kindA : kindB;
        int cLen = kindC == kindA ? 2 : 1;
        for (int i = 2; i < tree.size(); i++) {
            if (kindB == -1 && tree[i] != kindA) {
                kindB = tree[i];
                currLen++;
                kindC = tree[i];
                cLen = 1;
            } else if (tree[i] == kindA || tree[i] == kindB) {
                currLen++;
                if (kindC == tree[i]) 
                    cLen++;
                else {
                    kindC = tree[i];
                    cLen = 1;
                }
            } else {
                currLen = cLen + 1;
                kindA = kindC;
                kindC = tree[i];
                cLen = 1;
                kindB = tree[i];
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};