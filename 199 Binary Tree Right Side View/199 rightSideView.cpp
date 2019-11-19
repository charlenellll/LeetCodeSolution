// 1. BFS
// 4 ms, faster than 73.03%, the majority speed
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if( !root ) return res;
        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() ){
            int size = q.size();
            TreeNode* cur;
            for(int i = 0; i < size; i++ ){
                cur = q.front();
                q.pop();
                if( cur->left ) q.push( cur->left );
                if( cur->right ) q.push( cur->right );
            }
            res.push_back( cur->val ); // record the last node on this level
        }
        return res;
    }
};

// 2. DFS
// 4 ms, faster than 73.03%
class Solution {
private:
    vector<int> res;
    void dfs(TreeNode* root, int level){
        if( !root ) return;
        if( level > res.size() ) res.push_back( root->val );
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */