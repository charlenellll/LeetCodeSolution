// Read the question !!!!!!
// Since m and n not exceed 100, I can SCAN THIS PLANE ONCE!!
// Brutal force: O(M*N) TIME, O(1) SPACE
// 96 ms, beats 95.20%

class Solution{
private:
    int m = 0, n = 0;
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid){
        m = grid.size();
        if( m == 0 ) return 0;
        n = grid[0].size();
        int sum = 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
            if( grid[i][j] != 1 ) continue;
            sum += 4;
            for(int k = 0; k < 4; k++){
                int newx = i+direction[k][0], newy = j+direction[k][1];
                if(inArea(newx, newy) && grid[newx][newy] == 1 ) sum -= 1;
            }
        }
        return sum;
    }
}; 


// WRONG ANSWER USING BACKTRACKING!!!!!!!!!!!!-----------------

class Solution {
private:
    vector<vector<bool>> visited;
    int sum = 0, height = 0, width = 0;
    int direction[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    bool inArea(int x, int y){
        return x >= 0 && x < height && y >= 0 && y < width;
    }

    void findIsland(vector<vector<int>>& grid, int x, int y){
        visited[x][y] = true;
        if( grid[x][y] == 1 )
            sum += 4;
        int newx, newy;
        for(int i = 0; i < 4; i++){
            newx = x + direction[i][0];
            newy = y + direction[i][1];
            if( inArea(newx, newy) && grid[newx][newy] == 1) {
                sum -= 1;
                if (!visited[newx][newy]) {
                    findIsland(grid, newx, newy);
                }
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        height = grid.size();
        if( height == 0 ) return 0;
        width = grid[0].size();
        visited = vector<vector<bool>>(height, vector<bool>(width, false));

        findIsland(grid, 0, 0);
        return sum;
    }
};