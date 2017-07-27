class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> record;
        for( int i = 0; i < s.size(); i++ ){
            if(record.find(s[i]) == record.end())
                record[s[i]] = 1;
            else
                record[s[i]] ++;
        }
        
        for(int i = 0; i < t.size(); i++){
            if( record.find(t[i]) == record.end() )
                return false;
            else if( record.find(t[i]) != record.end() && record[t[i]] > 0 ){
                record[t[i]] --;
                if( record[t[i]] == 0 )
                    record.erase(t[i]);
            }
        }
        
        // I have already made sure that two strings are of the same length, so no need to check the status after for-loop
        return true;
    }
};