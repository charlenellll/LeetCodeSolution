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
        if( root == NULL )
            return res;
        
        queue< pair<TreeNode*,int> > q;
        q.push( make_pair(root, 0) );
        while( !q.empty() ){
            
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            // push back an empty vector when this level is not yet created in the result vector
            if( level == res.size() )
                res.push_back( vector<int>() );
            
            res[level].push_back( node->val );
            
            if( node->left )
                q.push( make_pair( node->left, level + 1) );
            if( node->right )
                q.push( make_pair( node->right, level + 1) );
        }
        return res;
    }
};


// fastest solution: Notice that vector<vector<int>> res
// can store the level order information indexed by the level number itself!

class Solution {
public:

    vector<vector<int>> rt_ans;

    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(rt_ans.size() == depth)
            rt_ans.push_back(vector<int>());
        
        rt_ans[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        buildVector(root,0);
        return rt_ans;
    }
};