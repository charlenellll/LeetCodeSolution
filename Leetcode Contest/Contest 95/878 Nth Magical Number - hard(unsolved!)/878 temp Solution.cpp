// Runtime Error Message:
// terminate called after throwing an instance of 'std::bad_alloc'
//   what():  std::bad_alloc
// 问题应该出在vector上，不能分配那么大的连续空间，需要改换方案，不要用vector

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        // i-th place stores the min value that can be divided by either A or B
        vector<long long> magic = vector<long long>(N+1, INT_MAX); 
        int minAB = min(A,B), maxAB = max(A,B);
        if( N == 1) return minAB;
        magic[1] = minAB, magic[2] = maxAB;
        int k = 3;
        while( k <= N ){
            int minMultBoth = minAB * magic[k-1];
            int minMultAorB = N * minAB;
            magic[k] = min(minMultBoth, minMultAorB) % (long long)(pow(10,9)+7);
            k++;
        }
        return magic[N];
    }
};