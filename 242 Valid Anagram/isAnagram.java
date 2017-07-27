public class Solution {
    public boolean isAnagram(String s, String t) {
        
        if( s.length() != t.length() )
            return false;
        
        // The wrapper class for char is Character
        Map<Character,Integer> record = new HashMap();
        for(int i = 0; i < s.length(); i++){
            if( !record.containsKey(s.charAt(i)) )
                record.put(s.charAt(i), 1);
            else
                // Should avoid declare new int here, I can just put record.get(s.charAt(i)) inside the put() function
                record.put(s.charAt(i), record.get(s.charAt(i))+1);
        }
        
        for( int i = 0; i < t.length(); i++ ){
            if( !record.containsKey(t.charAt(i)) )
                return false;
            else if( record.containsKey(t.charAt(i)) && record.get(t.charAt(i)) > 0 ){
                record.put( t.charAt(i), record.get(t.charAt(i))-1);
                if( record.get(t.charAt(i)) == 0 )
                    record.remove(t.charAt(i));
            }
        }
                                   
        return true;
    }
}