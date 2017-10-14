class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        assert(k > 0);
        
        // Calculate frequency of each element
        // The pair is (element, frequency)
        unordered_map<int,int> freq;
        for( int i = 0; i < nums.size(); i++ )
            freq[nums[i]]++ ;
        
        // Scan freq, and maintain a priority queue containing the top k largest frequncies and corresponding elements
        assert( k <= freq.size() );
        
        // To maintain the priority queue, use a min heap (based on frequency) as basis
        // The pair is (frequency, element)
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for( unordered_map<int,int>::iterator iter = freq.begin(); iter != freq.end(); iter++ ){
            
            if( pq.size() == k ){
                if( iter->second > pq.top().first ){
                    pq.pop();
                    pq.push( make_pair(iter->second, iter->first) );
                }
            }
            else
                pq.push( make_pair(iter->second, iter->first) );
        }
        
        vector<int> res;
        while( !pq.empty() ){
            res.push_back( pq.top().second );
            pq.pop();
        }
        
        return res;
    }
};