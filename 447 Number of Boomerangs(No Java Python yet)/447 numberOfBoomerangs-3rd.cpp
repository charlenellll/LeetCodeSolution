// 400 ms, faster than 80.84%
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        if( points.size() == 0 ) return res;
        unordered_map<int,int> dist; // store the square distance between two points
        for(int a = 0; a < points.size(); a++ ){
            for(int b = 0; b < points.size(); b++ )
                if( a != b){
                int distance = pow(points[a][0]-points[b][0],2) + pow(points[a][1]-points[b][1],2);
                dist[distance]++;
            }
            for(auto item: dist)
                if( item.second > 1 )
                    res += item.second * (item.second-1); // A(k,2) permutations
            dist.clear();
        }
        return res;
    }
};