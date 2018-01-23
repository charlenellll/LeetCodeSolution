
// Runtime error
// INput: [[1,4],[1,4]]

class Solution {
private:
    static bool compare(Interval a, Interval b){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if( intervals.size() == 0 ) return vector<Interval>();
        sort( intervals.begin(), intervals.end(), compare);
        for( vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); iter++ ){
            while( iter+1 != intervals.end() && iter->end >= (iter+1)->start ){
                iter->end = max(iter->end, (iter+1)->end);
                intervals.erase( iter+1 );
                iter++;
            }
        }
        return intervals;
    }
};


// Using another vector to return cannot let intervals know the change of result intervals
class Solution {
private:
    static bool compare(Interval a, Interval b){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if( intervals.size() == 0 ) return res;
        sort( intervals.begin(), intervals.end(), compare);
        for( vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); iter++ ){
            if( iter+1 != intervals.end() && iter->end >= (iter+1)->start )
                while( iter+1 != intervals.end() && iter->end >= (iter+1)->start ){
                res.push_back( Interval(iter->start, max(iter->end,(iter+1)->end)) );
                iter++;
            }
            else res.push_back(*iter);
        }
        return res;
    }
};


// Wrong code of Merge Sort: I still haven't solved the problem of indexes

class Solution {
private:
    static bool compare( Interval a, Interval b ){
        return a.start == b.start ? a.end < b.end : a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if( intervals.size() == 0 ) return vector<Interval>();
        sort( intervals.begin(), intervals.end(), compare );
        mergeSort( intervals, 0, intervals.size()-1 );
        return intervals;
    }
        
    int mergeSort(vector<Interval>& intervals, int left, int right){
        if( left == right ) return right;
        int mid = left + (right - left)/2;
        // do the right part first to make sure not changing the left part
        int rr = mergeSort(intervals, mid+1, right);
        int lr = mergeSort(intervals, left, mid);
        // the size of intervals has changed so I cannot use mergesort!
        return merging( intervals, left, rr-(mid-lr) );
    }
    
    int merging( vector<Interval>& intervals, int left, int right ){
        for( int i = left; i+1 <= right; i++){
            // must satisfy intervals[i].start <= intervals[i+1].start because it's already sorted
            while(  intervals[i].end >= intervals[i+1].start && i+1 <= right ){
                intervals[i].end = intervals[i+1].end;
                vector<Interval>::iterator iter = intervals.begin()+i+1;
                intervals.erase(iter);
                i++;
            }           
        }
        return intervals.size()-1;
    }
};