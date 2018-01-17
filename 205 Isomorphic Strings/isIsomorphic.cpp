// Using int array can be much faster, for this problem, see the third code

// optimizaed: 15 ms

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        
        unordered_map<int,int> rec1;
        unordered_map<int,int> rec2;
        for(int i = 0; i < n ; i++ ){
        	// notice when I do the comparison, when s[i] or t[i] is not in the map
        	// it will automatically create a (key,value) pair where the value = 0
            if( rec1[s[i]] != rec2[t[i]] )
                return false;
            // but since the index starts from 0, it can confuse with the default value 0 when key does not exist
            // use i+1 to avoid that
            rec1[s[i]] = i + 1;
            rec2[t[i]] = i + 1;            
        }
        return true;
    }
};


// my original version
// 17ms

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if( n == 0 && m == 0 ) return true;
        if( n == 0 || m == 0 || n != m ) return false;
        
        unordered_map<int,vector<int>> rec1;
        unordered_map<int,vector<int>> rec2;
        for(int i = 0; i < n ; i++ ){
        	// we can use "==" to compare if two vectors are equivalent
            if( rec1[s[i]] == rec2[t[i]] ){
                rec1[s[i]].push_back(i);
                rec2[t[i]].push_back(i);
            }
            else
                return false;
        }
        return true;
    }
};

// sample 6ms code:
// use int array instead of unordered_map since the key can only be characters

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int m1[256] = { 0 }, m2[256] = { 0 }, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};