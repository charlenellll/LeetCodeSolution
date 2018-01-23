/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// To keep the merging process correct, always compare the intervals in the input vector with the last element of result vector and revise the last element in the result vector

class Solution {
private:
    static bool compare(Interval a, Interval b){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if( intervals.size() <= 1 ) return intervals;
        vector<Interval> res;
        sort( intervals.begin(), intervals.end(), compare);
        res.push_back( intervals[0] );
        for( int i = 1; i < intervals.size(); i++ ){
            int curEnd = res.back().end;
            if(  curEnd >= intervals[i].start ){
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else
                res.push_back( intervals[i] );
        }
        return res;
    }
};