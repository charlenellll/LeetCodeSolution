// Solution 2: Map pattern letter and words to the last index they show up!! + Use istringstream to help read in the words
// more concise sample code 

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str); // Learn to use this one to read words!
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1; // record the index they both show up
        }
        return i == n;
    }
};


// Solution 1
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.6 MB, less than 92.86%

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> letter2word(26, ""); 
        unordered_map<string, char> word2letter;// bijection
        int l = 0; // word is str[l..r]
        for(int i = 0; i < pattern.size(); i++){
            if( l > str.size() ) 
                return false; // more letters than words
            int r = l;
            while(str[r] != ' ' && r < str.size())
                r++;
            string word = str.substr(l, r-l);
            if( letter2word[pattern[i]-'a'] != "" ){
                if( letter2word[pattern[i]-'a'] != word )
                    return false;
            }
            else
                letter2word[pattern[i]-'a'] = word;
            if( word2letter.find(word) != word2letter.end() ){
                if( word2letter[word] != pattern[i])
                    return false;
            }
            else
                word2letter[word] = pattern[i];
            l = r+1;
        }
        return l == str.size()+1; // whether more words than letters
    }
};