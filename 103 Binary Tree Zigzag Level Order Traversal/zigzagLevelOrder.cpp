// mine: iterative BFS with level information

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if( !root ) return result;
        
        queue<TreeNode*> q;
        q.push( root );
        int level = 0;
        
        while( !q.empty() ){
            int sz = q.size();
            vector<int> res;
            for( int i = 0; i < sz; i++ ){
                TreeNode* node = q.front();
                q.pop();
                res.push_back( node->val );
                if( node-> left ) q.push(node->left);
                if(node->right ) q.push(node->right);
            }
            if( level % 2 == 1 )
                reverse( res.begin(), res.end() );
            level++;
            result.push_back( res );
        }
        
        return result;
    }
};

// fastest: optimized recursive version: DFS with level information

class Solution {
private:
    void traverse(std::vector<std::vector<int>>& res, int level, TreeNode* node){
        if(!node) return;
        if(level>=res.size()) res.emplace_back(std::vector<int>{node->val});
        else if(level%2==0) res[level].emplace_back(node->val);
        else res[level].insert(res[level].begin(), node->val);
        traverse(res, level+1, node->left);
        traverse(res, level+1, node->right);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        traverse(res, 0, root);
        return res;
    }
};