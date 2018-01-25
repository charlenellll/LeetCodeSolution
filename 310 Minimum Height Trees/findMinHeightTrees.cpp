// 111ms

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> indegree(n, 0), res;
        unordered_map<int, unordered_set<int>> adj;
        for( auto edge: edges ){
            indegree[edge.first]++, indegree[edge.second]++;
            adj[edge.first].insert(edge.second), adj[edge.second].insert(edge.first);
        }
        int num = n;
        while( num > 2 ){
            unordered_set<int> remove;
            for( int i = 0; i < n; i++ )
                if( indegree[i] == 1 ){
                    remove.insert(i);
                }
            for( auto v: remove){
                indegree[v] = -1;
                for(auto neighbor: adj[v] ) indegree[neighbor]--;
                num --;
            }
        }
        for( int i = 0; i < n; i++ )
            if( indegree[i] >= 0 )
                res.push_back(i);
        return res;
    }
};

// The original one with debugging steps:

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // unordered_map<int,int> indegree;
        vector<int> indegree(n, 0), res;
        unordered_map<int, unordered_set<int>> adj;
        for( auto edge: edges ){
            indegree[edge.first]++, indegree[edge.second]++;
            adj[edge.first].insert(edge.second), adj[edge.second].insert(edge.first);
        }
        int num = n;
        while( num > 2 ){
            unordered_set<int> remove;
            for( int i = 0; i < n; i++ )
                if( indegree[i] == 1 ){
                    remove.insert(i);
                    //indegree.erase(v.first); - Wrong 1 !
                }
            for( auto v: remove){
                // indegree.erase( v ); - Wrong 2! for test case n==1, edges is empty, we should return [0], not []
                // I should not use unordered_map
                indegree[v] = -1;
                for(auto neighbor: adj[v] ) indegree[neighbor]--;
                num --;
            }
        }
        for( int i = 0; i < n; i++ )
            if( indegree[i] >= 0 )
                res.push_back(i);
        return res;
    }
};

// sample 32 ms code

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> degree(n);
    for (auto & e: edges) {
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
      degree[e.first]++;
      degree[e.second]++;
    }
    deque<int> todo;
    for (int i = 0; i < n; i++) {
      if (degree[i] <= 1) todo.push_back(i);
    }
    while (n > 2) {
      int m = todo.size();
      while (m-- > 0) {
        int i = todo.front();
        todo.pop_front();
        n--;
        for (int j: adj[i]) {
          if (--degree[j] == 1) todo.push_back(j);
        }
      }
    }
    vector<int> ans;
    for (int i: todo) ans.push_back(i);
    return ans;
  }
};