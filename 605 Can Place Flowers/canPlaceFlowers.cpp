// 19ms

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if( m == 0 || n > m ) return false;
        
        int count = 0;
        for(int i = 0; i < m; i++ ){
            if (flowerbed[i] == 0)
                if( ((i == 0) || (i-1 >=0 && flowerbed[i-1] == 0)) && ((i+1 < m && flowerbed[i+1] == 0)|| (i == m-1)))
                count ++, i++;
        }
        
        if( n <= count ) return true;
        return false;
    }
};



// sample 15ms code

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size() && n > 0; i++) {
            if(flowerbed[i] == 0 && (i == 0||flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                n--;
                flowerbed[i] = 1;
            }   
        }
        return n == 0;
    }
};