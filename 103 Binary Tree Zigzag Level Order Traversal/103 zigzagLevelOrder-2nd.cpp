// 2. Optimization: Using Vector to replace the Queue
// 0 ms, faster than 100.00% 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( !root ) return res;
        
        vector<TreeNode*> q, newQ;
        q.push_back(root);
        int level = 1;
        vector<int> curLevel;
        while( !q.empty() ){
            curLevel.clear();
            newQ.clear();
            for(int i = 0; i < q.size(); i++){ // process the whole level
                TreeNode* cur = q[i];
                curLevel.push_back( cur->val );
                if( cur->left ) newQ.push_back( cur->left );
                if( cur->right ) newQ.push_back(cur->right);
            }
            q = newQ;
            if( level % 2 == 0 )
                reverse(curLevel.begin(), curLevel.end());
            res.push_back( curLevel );
            level++;
        }
        return res;
    }
};

// 1. Using Queue
// 8 ms, faster than 40.82%
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( !root ) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        vector<int> curLevel;
        while( !q.empty() ){
            curLevel.clear();
            int size = q.size(); // record how many nodes on this level
            for(int i = 0; i < size; i++){ // process the whole level
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back( cur->val );
                if( cur->left ) q.push( cur->left );
                if( cur->right ) q.push(cur->right);
            }
            if( level % 2 == 0 )
                reverse(curLevel.begin(), curLevel.end());
            res.push_back( curLevel );
            level++;
        }
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