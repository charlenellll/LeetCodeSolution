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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        if( root == NULL )
            return res;
        
        if( root->left == NULL && root->right == NULL){
            res.push_back( to_string(root->val) );
            return res;
        }
        
        vector<string> leftS = binaryTreePaths(root->left);
        for( int i = 0; i < leftS.size(); i++ )
            res.push_back( to_string(root->val) + "->" + leftS[i]);
        
        vector<string> rightS = binaryTreePaths(root->right);
        for( int i= 0; i < rightS.size(); i++ )
            res.push_back( to_string(root->val) + "->" + rightS[i]);
        
        return res;
    }
};