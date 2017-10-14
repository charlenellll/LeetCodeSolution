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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        assert( p!=NULL && q!=NULL );//talk about this with interviewer

        if(root == NULL)
            return NULL;
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        // if(root->val == p->val || root->val == q->val || (p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val))
        return root;

        // can talk to the interviewer if I need to check if p and q are in the tree
        
        return NULL;
    }
};