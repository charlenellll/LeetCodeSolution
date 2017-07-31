public class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> stack = new Stack();
        
        for(int i = 0; i < s.length(); i++){
            if( s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{')
                stack.push( s.charAt(i) );
            else{
                if( stack.empty() ) // stack.size() == 0 also works
                    return false;
                
                char c = stack.peek();
                stack.pop();
                
                char match = ' ';
                switch( s.charAt(i) ){
                        case')': match = '('; break;
                        case']': match = '['; break;
                        case'}': match = '{'; break;
                }
                
                if( c != match )
                    return false;
            }
        }
        
        if( !stack.empty() )
            return false;
        
        return true;
    }
}