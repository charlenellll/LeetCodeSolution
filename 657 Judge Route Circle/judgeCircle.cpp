// Optimized my solution
// 19ms

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for( int i = 0; i < moves.size(); i++ ){
            if(moves[i] == 'U') y++;
            else if( moves[i] == 'D') y--;
            else if( moves[i] == 'L') x--;
            else x++;
        }
        if( x == 0 && y == 0 ) return true;
        return false;
    }
};

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for( int i = 0; i < moves.size(); i++ ){
            switch(moves[i]){
                case 'U':
                    y++;
                    // If not using break here, will compile error
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
        }
        if( x == 0 && y == 0 )
            return true;
        return false;
    }
};


// sample 16ms code

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (int i = 0; i < moves.size(); ++i) {
            if (moves[i] == 'U') {
                ++y;
            } else if (moves[i] == 'D') {
                --y;
            } else if (moves[i] == 'L') {
                --x;
            } else {
                ++x;
            }
        }
        if (x == 0 && y == 0) {
            return true;
        }
        return false;
    }
};

// 44ms
// Too slow!

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> hash;
        for( int i = 0; i < moves.size(); i++ ){
            char oppositeDir = opposite(moves[i]);
            if( hash[oppositeDir] > 0 )
                hash[oppositeDir]--;
            else
                hash[moves[i]]++;
        }
        for( auto v: hash )
            if( hash[opposite(v.first)] != v.second )
                return false;
        return true;
    }
    char opposite(char c){
        switch (c){
            case 'U':
                return 'D';
            case 'D':
                return 'U';
            case 'L':
                return 'R';
            case 'R':
                return 'L';
        }
        
    }
};