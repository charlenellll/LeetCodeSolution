// 运行时间：4ms 占用内存：484k
class Solution {
private:
    vector<int> memo;
public:
    int jumpFloor(int number) {//DP
        if( memo.size() > number ) return memo[number];
        memo = vector<int>(number+1, 0); //memo[i]表示上i级台阶的跳法（1-based）
        memo[1] = 1;
        memo[2] = 2;
        for(int i = 3; i <= number; i++)
            memo[i] = memo[i-1] + memo[i-2];
        return memo[number];
    }
};