class Solution {
private:
    vector<int> front;// front[i] stores the max # of stones one can get if one choose piles[i], taking from front
    vector<int> back;// back[i] stores the max # of stones one can get if one choose piles[i], taking from back
    void FDFS(vector<int>& piles, int index){
        if( index == piles.size() ) return;
        FDFS( piles, index+1 );
        front[index] = max(front[index], piles[index] + front[index+1]);
    }
    
    void BDFS(vector<int>& piles, int index){
        if( index < 0 ) return;
        BDFS(piles, index-1);
        back[index] = max(back[index], piles[index] + back[index-1]);
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        if( n == 1 ) return true;
        front = vector<int>(n,-1);
        back = vector<int>(n,-1);
        FDFS(piles, 0);
        BDFS(piles, n-1);
        
        int sum = 0;
        for(int i = 0; i < n; i++ ) sum += piles[i];
        int maxAlex = max(front[0], back[n-1]);
        return maxAlex > (sum - maxAlex);
    }
};