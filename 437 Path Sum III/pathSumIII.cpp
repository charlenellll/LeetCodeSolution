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
    // Main process. Find # of paths not necassarily contain the root vertex + find ones contain the root in the subprocedure
    int pathSum(TreeNode* root, int sum) {
        
        if(root == NULL)
            return 0;
        int res = 0;
        res += findPath( root, sum );
        res += pathSum( root->left, sum );
        res += pathSum( root->right, sum);
        
        return res;
    }
    
    // subprocedure: find # of paths that contain the root
private:
    int findPath(TreeNode* root, int sum){
        if(root == NULL)
            return 0;
        int res = 0;
        if(root->val == sum)
            res += 1;
        res += findPath(root->left, sum-root->val);
        res += findPath(root->right,sum-root->val);
        
        return res;
    }
};