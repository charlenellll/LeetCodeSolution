// 0 ms
// beats 100%

class Solution {
public:
    int numWays(int n, int k) {
        if( n == 0 || k == 0 || (k == 1 && n > 2)) return 0;
        int same = 0; // numSame[i] is # of ways that painted [0, i] posts, that i-th post's color same as i-1
        int diff = k; // numDiff[i] is # of ways that painted [0, i] posts, that i-th post's color diff from i-1
        int total = same + diff;
        for(int i = 1; i < n; i++){
            same = diff;
            diff = (k-1) * total;
            total = same + diff;
        }
        return total;
    }
};