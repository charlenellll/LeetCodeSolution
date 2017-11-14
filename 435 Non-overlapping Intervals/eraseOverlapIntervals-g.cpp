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
         if( a.end != b.end )
             return a.end < b.end;
         return a.start < b.start;
     }   
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        int n = intervals.size();
        if( n == 0 )
            return 0;

        sort(intervals.begin(), intervals.end(), compare);
        
        // the interval who ends the earlies is the first element, so res is at least 1
        int res = 1;
        // the index of the previous interval
        int pre = 0;
        for(int i = 1; i < n; i++)
            if( intervals[i].start >= intervals[pre].end ){
                res ++;
                pre = i;
            }
        
        return n-res;
    }
};

// Optimized version: using greedy algorithm