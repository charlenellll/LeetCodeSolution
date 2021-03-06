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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( !root ) return res;
        queue<TreeNode*> q;
        q.push( root );
        
        vector<int> curLevel;
        while( !q.empty() ){
            int size = q.size();
            curLevel.clear();
            for( int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back( cur->val );
                if( cur->left ) q.push(cur->left);
                if( cur->right ) q.push(cur->right);
            }
            res.push_back( curLevel );
        }
        return res;
    }
};