// Solution 1: ----
// Only 1 test case not passed: 精度的问题
// Input [[0,0],[94911151,94911150],[94911152,94911151]]
// Output 3
// Expected 2

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        unordered_map<double, int> record;
        for(int i = 0; i < points.size(); i++ ){ // fix a point, find the points w the same slope
            int samePoint = 1;
            for(int j = i+1; j < points.size(); j++){
                if( points[j][0] == points[i][0] && points[j][1] == points[i][1]) samePoint++;
                else if (points[j][0] == points[i][0] ) // points[j][1] != points[i][1]
                    record[INT_MAX] ++;
                else{ // points[j][0] != points[i][0]
                    double slope = (double)(points[j][1]-points[i][1]) / (double)(points[j][0]-points[i][0]);
                    record[slope]++;
                }
            }
            for(auto item: record)
                    res = max(res, item.second + samePoint);
            if(record.empty()) res = max(res, samePoint); // in case record is empty
            record.clear();
        }
        return res;
    }
};

// Or


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if( points.size() == 0 ) return 0;
        int res = 1;
        unordered_map<double, int> record;
        for(int i = 0; i < points.size(); i++ ){ // fix a point, find the points w the same slope
            int samePoint = 1;
            int vertical = 1;
            for(int j = i+1; j < points.size(); j++){
                if( points[j][0] == points[i][0] && points[j][1] == points[i][1]) samePoint++;
                else if (points[j][0] == points[i][0] && points[j][1] != points[i][1])
                    vertical ++;
                else{ // points[j][0] != points[i][0]
                    double slope = (double)(points[j][1]-points[i][1]) / (points[j][0]-points[i][0]);
                    record[slope]++;
                }
            }
            for(auto item: record)
                if( item.second >= 1 )
                    res = max(res, item.second + samePoint);
            if(record.empty()) res = max(res, samePoint); // in case record is empty
            res = max(res, vertical );
            record.clear();
        }
        return res;
    }
};