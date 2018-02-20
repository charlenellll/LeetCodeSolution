// Optimization 3 (based on Optimization 2): Only use one array
// 38 ms, beats 91.48%

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int record[26] = {0};
        int index = n+1;
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            if( record[idx] == 0 ) record[idx] = i+1;
            else record[idx] = -1;
            // we can't set it to 0 to conform all undesired cases since it will compromise the if-statement above!
        }
        for( int i = 0; i < 26; i++){
        	// Note that: the elements appeared multi-times has record of -1, while the untouched characters in the record has value of 0!
            if( record[i] != 0 && record[i] != -1) // this is important!
            // we can change it to: if(record[i] > 0)
                index = min(index, record[i]);
        }
        return index == n+1? -1 : index-1;
    }
};

// for Optimization 2: I don't need the if-else statement when I construct the index array, and I don't need to initialize it either
// 39 ms, 77%

class Solution {
public:
    int firstUniqChar(string s) {
        int record[26] = {0};
        int index[26];
        for(int i = 0; i < s.size(); i++){
            index[s[i] - 'a'] = i;
            record[s[i] - 'a']++;
        }
        int res = INT_MAX;
        for( int i = 0; i < 26; i++ ){
            if( record[i] == 1 )
                res = min(res, index[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};


// Optimization 2 based on Optimization 1: use another int array to store the index
// 43ms, 68.39%

class Solution {
public:
    int firstUniqChar(string s) {
        int record[26] = {0};
        int index[26] = {-1};
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';
            if( record[idx] == 0 )
                index[idx] = i;
            else
                index[idx] = -1;
            record[idx]++;
        }
        int res = INT_MAX;
        for( int i = 0; i < 26; i++ ){
            if( record[i] == 1 )
                res = min(res, index[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};



// Optimization 1: use a int array instead of unordered_set
// 44ms, beats 68.39%

class Solution {
public:
    int firstUniqChar(string s) {
        int record[26] = {0};
        for(int i = 0; i < s.size(); i++){
            record[s[i]-'a']++;
        }
        for( int i = 0; i < s.size(); i++ ){
            if( record[s[i]-'a'] == 1 )
                return i;
        }
        return -1;
    }
};


// 69ms, beats 42.9%

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> record;
        for(int i = 0; i < s.size(); i++){
            record[s[i]]++;
        }
        for( int i = 0; i < s.size(); i++ ){
            if( record[s[i]] == 1 )
                return i;
        }
        return -1;
    }
};