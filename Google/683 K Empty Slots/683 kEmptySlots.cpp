// Solution 2
// 在days数组中找一个区间[left, left+1 , ..., left+k, right]使得中间的日期都比left和right靠后
// 如果任何一个位置的日期比left\right小，则考虑窗口从这个位置开始
// 140 ms
// beats 55.53%
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i = 0; i < flowers.size(); i++) days[flowers[i]-1] = i+1;
        int left = 0, right = k+1, res = INT_MAX;
        for(int i = 0; right < flowers.size(); i++){
            if( days[i] < days[left] || days[i] <= days[right] ){ // 任意不符合条件（days[i] < days[left] || days[i] < days[right]）与结束条件 days[i] == days[right]的合并
                if( i == right ) res = min(res, max(days[left], days[right])); // a valid window
                left = i, right = k+1+i;
            }
        }
        return res == INT_MAX? -1 : res; 
    }
};


// Solution 1
// 1220 ms
// slow but it worked
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> numFlowers(n+1, 0); //the number of flowers in the range[1, place]
        vector<bool> hasFlower(n+1,false); // crucial! Have to make sure both spots have flowers before compare the numFlowers
        for(int i = 0; i < n; i++){
            hasFlower[flowers[i]] = true;
            if( i >= 1 && ((flowers[i] > k+1 && hasFlower[flowers[i]-k-1] == true && numFlowers[flowers[i]] == numFlowers[flowers[i]-k-1] ) || (flowers[i]+k+1 <= n && hasFlower[flowers[i]+k+1] == true && numFlowers[flowers[i]]+1 == numFlowers[flowers[i]+k+1])))
                return i+1;
            for(int j = flowers[i]; j <= n; j++)
                numFlowers[j]++;
        }
        return -1;
    }
};


// sample 124 ms code:
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> pos(n, 0);
        if (k > n) {
            return -1;
        }
        for (int i = 0; i < n; ++ i) 
            pos[flowers[i] - 1] = i + 1;
        int left = 0, right = k + 1;
        int ans = n + 1;
        for (int i = 0; i < n; ++ i) {
            if (i == right) {
                ans = min(ans, max(pos[left], pos[right]));
            }
            if (pos[i] < pos[left] || pos[i] <= pos[right]) {
                left = i;
                right = i + k + 1;
                if (right >= n)
                    break;
            }
        }
        ans = (ans == n + 1) ? -1 : ans;
        return ans;
    }
};