public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        
        Map<Integer, Integer> record = new HashMap<Integer,Integer>(); 
        for(int i = 0; i < nums1.length; i++){
            if(!record.containsKey(nums1[i]))
                record.put(nums1[i], 1);
            else{
                int v = record.get(nums1[i]);
                record.put(nums1[i], v+1);
            }
        }
        
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for(int i = 0; i < nums2.length; i++)
            if( record.containsKey(nums2[i]) && record.get(nums2[i]) > 0){
                temp.add(nums2[i]);
                int v = record.get(nums2[i]);
                record.put(nums2[i], v-1);
                if( v-1 == 0 )
                    record.remove(nums2[i]);
            }
        
        Integer[] result = temp.toArray(new Integer[] {});
        int[] res = new int[result.length];
        for(int i = 0; i < result.length; i++)
            res[i] = result[i].intValue();
        return res;
    }
}