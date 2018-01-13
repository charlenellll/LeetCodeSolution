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
    int DFS(TreeNode* root, vector<vector<int>> res){ // wrong point 1: need to use "&res"!
        
        // warning: !root is standard
        if( root == NULL ) return 0;
        
        // wrong point 2: left right have to be extracted from max() or their order cannot be guaranteed! 
        int height = 1 + max( DFS(root->left, res), DFS(root->right, res) ); 
        if( height - 1 < res.size() ) res[height - 1].push_back( root->val );
        else res.push_back( vector<int>( root->val ) );
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> result;
        DFS(root, result);
        return result;
    }
};



class Solution {
private:
    // return the distance of the current root and the leaf level
    int DFS(TreeNode* root, vector<vector<int>> res){ // wrong point 1: need to use "&res"!
        
        // warning: !root is standard
        if( root == NULL ) return 0;
        
        // left right are extracted
        int left = DFS(root->left, res), right = DFS(root->right, res);
        int height = 1 + max(left,right), len = res.size(); 
        if( height - 1 < len ) 
            res[height - 1].push_back( root->val );
        else 
            res.push_back( vector<int>( root->val ) );
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> result;
        DFS(root, result);
        return result;
    }
};