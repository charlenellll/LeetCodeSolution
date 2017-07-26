#include <unordered_set>
#include <vector>
using namespace std;

// The underlying mechanism for unordered set is hash table
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // O(n)
        unordered_set<int> record( nums1.begin(), nums1.end() );
        
        // O(n)
        unordered_set<int> resultSet;
        for( int i = 0; i < nums2.size(); i++)
            if( record.find(nums2[i]) != record.end() )
                resultSet.insert( nums2[i] );
        // O(n)      
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};