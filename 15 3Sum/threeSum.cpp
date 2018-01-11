class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        if( nums.size() < 3 )
            return res;
        
        sort( nums.begin(), nums.end() );
        
        for( int index = 0; index < nums.size() - 2; index ++ ){
            
            if( nums[index] > 0 ) break;
            if( index >0 && nums[index] == nums[index-1] ) continue;
            
            int p = index + 1;
            int q = nums.size() - 1;
            while( p < q ){
                int sum = nums[index] + nums[p] + nums[q];
                if( sum == 0 ){
                    int result[3] = {nums[index], nums[p], nums[q]};
                    res.push_back( vector<int>( result, result+3 ) );
                    while( p < q && nums[p] == nums[p+1] ) p++;
                    while( p < q && nums[q] == nums[q-1] ) q--;
                    p++;
                    q--;
                }
                else if( sum < 0 ) p++;
                else q--;
            }            
        } 
        
        return res;
    }
};