// 0 ms beats 100%

class Solution{
private:
    vector<string> res;
    // find the numbers can be got by totalNum lights: maxNum里挑totalNum个的组合问题
    void DFS(int maxNum, int totalNum, int curIndex, vector<string>& vec, int sum){
        if( totalNum == 0 ) {
            vec.push_back(maxNum == 4?to_string(sum):(to_string(sum).size()==1?"0"+to_string(sum):to_string(sum)));
            return;
        }
        if( curIndex == maxNum ) return;
        DFS(maxNum, totalNum, curIndex + 1, vec, sum);
        sum += pow(2, curIndex);
        if ((maxNum == 4 && sum > 11) || (maxNum == 6 && sum > 59)) return;
        DFS(maxNum, totalNum - 1, curIndex + 1, vec, sum);
    }
public:
    vector<string> readBinaryWatch(int num) {
        for(int i = max(0, num-6); i <= min(4, num); i++){ // control how many lights are hour-light - Pruning the backtracking tree
            vector<string> hours, minutes;
            DFS(4, i, 0, hours, 0), DFS(6, num-i, 0, minutes, 0);
            for(auto hour: hours)
                for(auto minute: minutes){
                res.push_back(hour + ":" + minute);
            }
        }
        return res;
    }
};


// Bitmap
// simple code:
vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num) // 竖线是二进制运算的或，因为h左移了六位，后六位为0，异或 m 相当于把它加到右边六位
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}