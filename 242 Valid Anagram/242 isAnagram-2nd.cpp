// Optimization 2: use a small vector to serve as a map
// 12 ms, faster than 81.08% 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ) return false;
        vector<int> record(26,0); // in this problem the string contains only lowercase alphabets
        for(int i = 0; i < s.size(); i++)
            record[s[i]-'a']++;
        for(char item: t){
            if( record[item-'a'] == 0 )
                return false;
            else
                record[item-'a']--;
        }
        return true;
    }
};

// Optimization1: judge the length of two strings before everything
// 20 ms, faster than 39.18%: No improvement on time consumption but some improvement of space on overall performances
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ) return false;
        unordered_map<char,int> record;
        for(int i = 0; i < s.size(); i++)
            record[s[i]]++;
        for(char item: t){
            if( record.find(item) == record.end() )
                return false;
            else{
                record[item]--;
                if(record[item] == 0)
                    record.erase(item);
            }
        }
        return true;
    }
};

// Solution 1: straight forward
// 20 ms, faster than 39.18%

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> record;
        for(int i = 0; i < s.size(); i++)
            record[s[i]]++;
        for(char item: t){
            if( record.find(item) == record.end() )
                return false;
            else{
                record[item]--;
                if(record[item] == 0)
                    record.erase(item);
            }
        }
        return record.size() == 0;
    }
};