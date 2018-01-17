// I will try the 13ms method(just use index to get the minDist) when I get time

// Optimization of my method: 18ms
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        unordered_map<string, vector<int>> record;
        int minDist = INT_MAX;
        if( word1 == word2 ){
            for( int i = 0; i < words.size(); i++ ){
                if( words[i] == word1 )
                    if( record[word1].size() > 0 ){
                        int n = record[word1].size();
                        minDist = min(minDist, i - record[word1][n-1]);
                    }
                record[words[i]].push_back(i);
            }
        }
        else{
            for( int i = 0; i < words.size(); i++ )
                record[words[i]].push_back(i);
            
            vector<int> &v1 = record[word1], &v2 = record[word2];
            int p = 0, q = 0;
            while( p < v1.size() && q < v2.size() ){
                minDist = min(minDist, abs(v1[p] - v2[q]));
                (v1[p] < v2[q]) ? p++ : q++;
            }
        }
        return minDist;
    }
};


// 24ms

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        // for the speed I skipped the assert of words.size() here although I don't want to
        unordered_map<string, vector<int>> record;
        for( int i = 0; i < words.size(); i++ )
            record[words[i]].push_back(i);
        
        // skipped the assert of "record can find word1 word2"
        int minDist = INT_MAX;
        if( word1 == word2 ){ // for safety I would do an assert of record[word1].size() > 1 here but it will be much slower           
            vector<int> &p = record[word1];
            for(int j = 1; j < p.size(); j++ )
                minDist = min(minDist, abs(p[j] - p[j-1]));
        }
        else{
            vector<int> &v1 = record[word1], &v2 = record[word2];
            int p = 0, q = 0;
            while( p < v1.size() && q < v2.size() ){
                minDist = min(minDist, abs(v1[p] - v2[q]));
                (v1[p] < v2[q]) ? p++ : q++;
            }
        }
        return minDist;
    }
};

// sample 13ms code
// since this problem didn't mention large amount of request of find(), I don't need to extract the find() method
// It is reasonable to just use indexes to find the min distance

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX, idx1 = words.size(), idx2 = -words.size();
        for(int i = 0; i < words.size(); i++) {
            if(words[i] == word1) idx1 = word1 == word2? idx2 : i;
            if(words[i] == word2) idx2 = i;
            res = min(res, abs(idx1 - idx2));
        }
        return res;
     }
};