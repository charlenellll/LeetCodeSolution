/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // return the distance of the current root and the leaf level
    int DFS(TreeNode* root, vector<vector<int>>& res){

        if( !root ) return 0;
        
        int left = DFS(root->left, res), right = DFS(root->right, res);
        int height = 1 + max( left, right ); 
        if( height - 1 < res.size() ) res[ height -1 ].push_back( root->val );
        else res.push_back( vector<int>{ root->val } );
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {

        vector<vector<int>> result;
        DFS(root, result);
        return result;
    }
};

// the fastest solution:

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root);
        return res; 
    }
    
    int dfs(vector<vector<int>> &res, TreeNode* root){
        if(!root){
            return -1;
        }
        
        // it is weired
        int len = 1 + max(dfs(res, root->left), dfs(res, root->right));
        if(len>=res.size()){
            res.resize(1+len);
        }       
        
        res[len].push_back(root->val);
        
        return len;
        
    }
    
 
};