// 8 ms, faster than 98.56% 

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // the new vector stores its distance to the closest person (first, on the left; then half of the locations will be overwrite by the distance to the closest person on the right)
        vector<int> dist(seats.size(), -1);
        int lastOccupied = -1, maxDist = 0;
        for(int i = 0; i < seats.size(); i++){
            if( seats[i] == 1 ){
                dist[i] = 0;
                for(int j = i-1; (lastOccupied == -1 && j >= 0) || (lastOccupied != -1 && j > (lastOccupied + i)/2 ) ; j-- )
                    dist[j] = dist[j+1]+1;
                lastOccupied = i;
            }
            else if( i > 0 ) dist[i] = dist[i-1]+1;
        }
        for( int i = 0; i < dist.size(); i++ )
            maxDist = max(maxDist, dist[i]);
        return maxDist;
    }
};