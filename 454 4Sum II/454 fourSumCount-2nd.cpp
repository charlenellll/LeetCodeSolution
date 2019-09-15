// Solution 2: only use one map to store the sum of A and B, traverse C and D combinations
// 152 ms, faster than 85.30% 

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> record;
        int n = A.size(), res = 0;
        for(int i = 0; i < n; i++ )
            for(int j = 0; j <n; j++){
                record[A[i]+B[j]]++;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++ ){
                if( record.find( - (C[i] + D[j]) ) != record.end() )
                    res += record[- (C[i] + D[j])];
            }
        return res;
    }
};

// Solution 1: 将A+B和C+D分别放在两个search table中
// TLE 哭哭。思路没问题，只是刚好超过了Leetcode时限。

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> record1, record2;
        int n = A.size(), res = 0;
        for(int i = 0; i < n; i++ )
            for(int j = 0; j <n; j++){
                record1[A[i]+B[j]]++;
                record2[C[i]+D[j]]++;
            }
        for(auto item1: record1)
            for(auto item2: record2 ){
                if( item1.first + item2.first > 0 )
                    break;
                else if( item1.first + item2.first == 0 )
                    res += item1.second * item2.second;
                else
                    continue;
            }
        return res;
    }
};