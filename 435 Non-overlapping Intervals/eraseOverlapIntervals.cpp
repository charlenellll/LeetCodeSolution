/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool compare(const Interval& a, const Interval& b){
         if( a.start != b.start )
             return a.start < b.start;
         return a.end < b.end;
     }   
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        int n = intervals.size();
        if( n == 0 )
            return 0;

        sort(intervals.begin(), intervals.end(), compare);
        
        // Let memo[i] be the longest non-overlapping interval sequence in intervals[0..i]
        vector<int> memo(n, 1);

        
        for(int i = 1; i < n; i++)
            //memo[i]
            for(int j = 0; j < i; j++)
                // We can see if each interval ends earlier, it's more likely to leave room for more intervals: see optimization using greedy algorithm
                if(intervals[i].start >= intervals[j].end)
                    memo[i] = max(memo[i], 1 + memo[j]);
        
        int res = 0;
        for(int i = 0; i < n; i++)
            res = max(res, memo[i]);
        
        return n-res;
        
    }
};

// Pure Dynamic Programming version.