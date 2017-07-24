public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] freqS = new int[26];
        int[] freqP = new int[26];
        List<Integer> index = new ArrayList<Integer>();
        
        for(int i=0; i<p.length(); i++)
            freqP[p.charAt(i)-'a']++;
        
        int l = 0, r = -1;
        while(l < s.length()){
            if(r-l+1 <= p.length() && r+1 < s.length())
                freqS[s.charAt(++r)-'a']++;
            else
                freqS[s.charAt(l++)-'a']--;
            if(Arrays.equals(freqS,freqP))
                index.add(l);
        }
        return index;
    }
}