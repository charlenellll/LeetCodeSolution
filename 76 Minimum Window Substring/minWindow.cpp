class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> record;
        for( int i = 0; i < t.size(); i++ )
                record[t[i]] ++;
        
        int l = 0, minl = 0, minSize = s.size()+1, cnt = 0;
        // First, move the right pointer of the window to find substring containing t's characters
        for( int r = 0; r < s.size(); r++ )    
            if( record.find(s[r]) != record.end() ){
                
                // if it's > 0 before decreasing, then it is in the substring that makes up t
                if( record[s[r]]-- > 0 )
                        cnt++;
                
                // when I find a substring containing t, try to minimize the window size
                // move l forward
                while( cnt == t.size() ){
                    if( r-l+1 < minSize ){
                        minl = l;
                        minSize = r-l+1;
                    }
                    if( record.find(s[l]) != record.end() ){                       
                        // if it is >= 0 before increasing, itself is in the substring that makes up t
                        if( record[s[l]]++ >= 0 )
                            cnt--;
                    }
                    l++;
                }
            }
        if( minSize > s.size() )
            return "";
        return s.substr( minl, minSize );   
    }
};