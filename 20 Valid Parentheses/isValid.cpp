class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stack;     
        for( int i = 0; i < s.size(); i++){            
            if( s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push( s[i] );           
            else{
                if( stack.size() == 0 )
                    return false;
                
                char c = stack.top();
                stack.pop();
                
                char match;
                switch( s[i] ){
                    case ')': match = '('; break;
                    case ']': match = '['; break;
                    case '}': match = '{'; break;
                }
                
                if( c != match )
                    return false;
            }
        }
        
        if( stack.size() != 0 )
            return false;

        return true;
    }
};