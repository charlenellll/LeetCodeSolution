// A's size just need to cover B (>= B), if B is not found, we should + 1 more A to allow all characters in A can be sliding through by a window of size of B
// Generally, size of repeatedA should be >= B or exactly >= B + 1 A
// 7ms, 77.59%

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string str = A;
        int count = 1;
        if( B.find_first_not_of(A) != B.npos )
            return -1;
        while( str.size() < B.size() ){
            str += A, count++;
        }
        if( str.find(B) != str.npos ){
            return count;
        }
        str += A, count++;
        if( str.find(B) != str.npos ){
            return count;
        }
        else return -1;
    }
};
