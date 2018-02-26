// 7 ms
// unordered_set's space complexity id smaller than int array in this problem
// since the length of J <= 50

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> record;
        int count = 0;
        for( int i = 0; i < J.size(); i++ ){
            record.insert(J[i]);
        }
        for( int i = 0; i < S.size(); i++){
            if( record.find(S[i]) != record.end() ) count++;
        }
        return count;
    } 
};


// 8 ms
// The first solution I can think of was:
// Use an int array as a set
// However, since unordered_set and int array both use linear time to hash, using set's space complexity is smaller because this problem explicitly states that the length of J <= 50 while an int array takes 256 elements

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewel[256] = {0};
        int count = 0;
        for( int i = 0; i < J.size(); i++ ){
            jewel[J[i]-'A'] = 1;
        }
        for( int i = 0; i < S.size(); i++){
            if( jewel[S[i]-'A'] == 1 ) count++;
        }
        return count;
    } 
};

// 8 ms
// Use the find() function of string object: the code is quite neat
// Drawback: be careful of using find()! Because it's not linear time!!

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for( int i = 0; i < S.size(); i++){
            if( J.find(S[i]) != J.npos ) count++;
        }
        return count;
    }
};

