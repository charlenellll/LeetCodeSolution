// So far, the solution is the only one, but based on the detail, my soluitons can still vary in speed:
// conclution: don't use a = a + b, use a += b instead !!

// 2 ms, beats 45.04%, the fastest solution
// Use res[j] += res[j-1];

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j > 0; j--){
                res[j] += res[j-1];
            }
        }
        return res;
    }
};


// 3 ms, beats 0.55%
// Use res[j] = res[j] + res[j-1]; => this is slower!!

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j > 0; j--){
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};