// Solution 1 optimization: O(M+N)
// 18ms

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        assert( words.size() > 1 );
        
        unordered_map<string, vector<int>> record;
        for(int i = 0; i < words.size(); i++ ){
            record[words[i]].push_back(i);
        }
        
        int p = 0, q = 0, minDist = INT_MAX;
        while( p < record[word1].size() && q < record[word2].size() ){
            minDist = min(minDist, abs(record[word1][p] - record[word2][q]));
            // because I get the index vector in one pass, the index in record[word1] and record[word2] must be increasing
            // we can just move the smaller index toward the bigger one to avoid repeatedly calculate this combination
            record[word1][p] < record[word2][q] ? p++ : q++;
        }
        
        assert( minDist < INT_MAX );
        return minDist;
    }
};


// Solution 1: O(M*N)
// Do it in 2 pass: 1 pass to construct unordered_map, one iteration to find the minimum
// But it is sometimes faster than do-it-in-one-pass since it only iterates through the word1 word2 vectors once unrepeatedly while do-it-in-onr-pass repeats.
// sometimes 22ms sometimes 21ms

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        assert( words.size() > 1 );
        
        unordered_map<string, vector<int>> record;
        for(int i = 0; i < words.size(); i++ ){
            record[words[i]].push_back(i);
        }
        
        int n = record[word1].size(), m = record[word2].size();
        int minDist = INT_MAX;
        for(int i = 0; i < n ; i++ )
            for(int j = 0; j < m; j++ ){
                int dist = record[word1][i] - record[word2][j];
                if( dist > 0 ){
                    if( minDist > dist ) minDist = dist;
                }
                else{
                    if( minDist > -dist ) minDist = -dist;
                }
            }
        
        assert( minDist < INT_MAX );
        return minDist;
    }
};

// Solution 2: O(M*N)
// Do it in one pass: it repeatly calculated combinations of two indexes
// but if I use a marking (2-D array/vector) it will be memory limit exceed

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        assert( words.size() > 1 );
        
        int minDist = INT_MAX;
        unordered_map<string, vector<int>> record;
        for(int i = 0; i < words.size(); i++ ){
            if( words[i] == word1 )
                if( record.find(word2) != record.end() )
                    for( int j = 0; j < record[word2].size(); j++){
                        int dist = record[word2][j]-i;
                        if( dist >0 ) minDist = min(minDist, dist);
                        else minDist = min(minDist, -dist);
                    }
            if( words[i] == word2 )
                if( record.find(word1) != record.end() )
                    for( int j = 0; j < record[word1].size(); j++){
                        int dist = record[word1][j] - i;
                        if( dist > 0 ) minDist = min(minDist, j-i);
                        else minDist = min(minDist, -dist);
                    }
            record[words[i]].push_back(i);
        }
        
        assert( minDist < INT_MAX );
        return minDist;
    }
};