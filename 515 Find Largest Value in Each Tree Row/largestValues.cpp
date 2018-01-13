/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// use for-loop instead of make_pair(node, level), is faster

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        if(!root) return res;

        queue< TreeNode*> q;
        q.push( root );
             
        while( !q.empty() ){
            int sz = q.size(), curMax = INT_MIN;
            for( int i = 0; i < sz; i++ ){
                TreeNode* node = q.front();
                q.pop();
                curMax = max(curMax, node->val);
                // I made a mistake here! notice that (!node->left) means node->left is NULL!! (node->left) meas it's not NULL!
                if( node->left ) q.push( node->left);
                if( node->right ) q.push( node->right);
            }
            res.push_back(curMax);
        }
        return res;
    }
};


// Use pair<TreeNode*, int>
// This is slower 

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        if(!root) return res;

        queue< pair<TreeNode*,int> > q;
        q.push( make_pair(root,0) );
        
        int curLevel = 0;
        int curMax = root->val;
        while( !q.empty() ){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            // level > curLevel
            if( level > curLevel ){
                res.push_back( curMax );
                curLevel = level;
                curMax = node->val;
            }
            // level == curLevel
            else{
                if( node->val > curMax )
                    curMax = node->val;
            }
            
            if( node->left ) q.push( make_pair(node->left, level + 1));
            if( node->right ) q.push( make_pair(node->right, level + 1));
        }
        res.push_back( curMax );
        return res;
    }
};