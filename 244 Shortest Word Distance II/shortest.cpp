// 34ms: 86.82%
// Optimization 2

class WordDistance {
private:
    unordered_map<string, vector<int>> record;
public:
    WordDistance(vector<string> words) {
        assert( words.size() > 1 );
        for( int i = 0; i < words.size(); i++ )
            record[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int p =0, q = 0, minDist = INT_MAX;
        // Just optimized this one line and the reference below
        vector<int> &v1 = record[word1], &v2 = record[word2];
        while( p < v1.size() && q < v2.size() ){
            // optimization: don't extract the int "dist"
            minDist = min(minDist, abs(v1[p] - v2[q]));
            (v1[p] < v2[q] ) ? p++ : q++;
        }
        return minDist;
    }
};

// 36ms
// Optimization 1: because I will traverse record[word1] and record[word2], 
// it is faster if I made references of both of them.
class WordDistance {
private:
    unordered_map<string, vector<int>> record;
public:
    WordDistance(vector<string> words) {
        assert( words.size() > 1 );
        for( int i = 0; i < words.size(); i++ )
            record[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int p =0, q = 0, minDist = INT_MAX;
        // Just optimized this one line and the reference below
        vector<int> &v1 = record[word1], &v2 = record[word2];
        while( p < v1.size() && q < v2.size() ){
            int dist = v1[p] - v2[q];
            minDist = min(minDist, abs( dist));
            (dist < 0 ) ? p++ : q++;
        }
        return minDist;
    }
};


// 43ms
// My first version based on the optimization of solution 1 of 243

class WordDistance {
private:
    unordered_map<string, vector<int>> record;
public:
    WordDistance(vector<string> words) {
        assert( words.size() > 1 );
        for( int i = 0; i < words.size(); i++ )
            record[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int p =0, q = 0, minDist = INT_MAX;
        while( p < record[word1].size() && q < record[word2].size() ){
            int dist = record[word1][p] - record[word2][q];
            minDist = min(minDist, abs( dist));
            dist < 0? p++ : q++;
        }
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */


// 34 ms sample code


class WordDistance {
public:
    WordDistance(vector<string> words) {
        mp.reserve(words.size());
        
        for (int i=0; i<words.size(); ++i){
            mp[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int best = INT_MAX;
        vector<int> & v1 = mp[word1], & v2 = mp[word2];
        
        int p1=0, p2=0;
        
        while (p1 < v1.size() && p2 < v2.size()){
            best = min(best, abs(v1[p1] - v2[p2]));
            // If I delete the first 2 conditions it will be 38ms
            if (p1 < v1.size() && (p2 >= v2.size() || v1[p1] < v2[p2])){
                ++p1;
            }
            else{
                ++p2;
            }
        }
        
        //best = min(best, abs(v1[p1] - v2[p2]));
        
        return best;
    }
    
private:
    unordered_map<string, vector<int>> mp;
};