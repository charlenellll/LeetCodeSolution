// O(n^2) time
// O(n) space
// 188 ms
// beats 67.25%

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int, int> dist;
            for(int j = 0; j < points.size();j++){
                if(j != i){
                    int a = points[i].first - points[j].first;
                    int b = points[i].second - points[j].second;
                    dist[a*a+b*b]++;
                }
            }
            for(unordered_map<int,int>::iterator iter = dist.begin(); iter != dist.end(); iter++)
                res += iter->second * (iter->second - 1);
        }
        return res;
    }
};