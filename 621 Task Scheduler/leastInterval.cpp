class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int m = tasks.size();
        int tasknum[26] = {0};
        for(int i = 0; i < m; i++ )
                tasknum[tasks[i]-'A']++;
        
        int time = 0;
        sort( tasknum, tasknum + 26 );
        while( tasknum[25] != 0 ){
            int i = 0;
            while( i <= n && tasknum[25] != 0 ){
                if( i < 26 && tasknum[25-i] > 0 )
                    tasknum[25-i] --;
                time ++;
                i ++;
            }
            sort( tasknum, tasknum + 26 );
        }
        
        return time;
    }
};