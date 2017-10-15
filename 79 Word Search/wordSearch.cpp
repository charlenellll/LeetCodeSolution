class Solution {
private:
    // Important to use this array to represent movement in 4 directions
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;
    bool inArea( int x, int y){
        return x >=0 && x < m && y >= 0 && y < n;
    }
    
    // Searching for word[index..word.size()] starts from board[startx][starty]
    bool searchWord( const vector<vector<char>>& board, const string& word, int index, int startx, int starty ){
        
        if( index == word.size() - 1 )
            return board[startx][starty] == word[index];
        
        if( board[startx][starty] == word[index] ){
            
            // Occupy this position
            visited[startx][starty] = true;
            // Searching in four directions starts from startx,starty
            for(int i = 0; i < 4; i++){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if( inArea(newx,newy) && !visited[newx][newy] && searchWord(board, word, index+1, newx, newy) )
                    return true;
            }
            visited[startx][starty] = false;
        }
        
        return false;
    }
        
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        assert( m > 0 );
        n = board[0].size();
        
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++ )
                if(searchWord(board, word, 0, i, j))
                    return true;
        
        return false;
    }
};