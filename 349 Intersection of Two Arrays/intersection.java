public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        Set<Integer> record = new HashSet();
        for(int i = 0; i < nums1.length; i++)
            record.add(nums1[i]);
        
        Set<Integer> resultSet = new HashSet();
        for(int i = 0; i < nums2.length; i++)
            if( record.contains(nums2[i]) )
                resultSet.add(nums2[i]);
        
        // This time I'm using the method of converting a Set to an int Array, maybe there are other ways
        Integer[] temp = resultSet.toArray(new Integer[] {});
        int[] res = new int[temp.length];
        for(int i = 0; i < temp.length; i++)
            res[i] = temp[i].intValue();
        
        return res;
        
    }
}