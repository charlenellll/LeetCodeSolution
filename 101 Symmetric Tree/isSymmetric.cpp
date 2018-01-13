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
    bool isSymmetricTree(TreeNode* p, TreeNode* q){

        if( !p && !q ) return true;
        // mistake 2:
        if( (!p && q) || (!q && p) ) return false;
        // mistake 1 I made: for two TreeNode pointer, I cannot use p==q to decide if their value are the same!
        // need to use p->val and q->val !!
        // after adding this, another problem: NULL pointer cannot point to "val" field
        // mistake 2: I have to make sure they both are not NULL before I could finally compare their vals
        if( p->val == q->val )
            if( isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left) )
                return true;
        
        return false;
    }    
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        
        return isSymmetricTree(root->left, root->right);
    }
};


// fastest solution: more concise

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return dfs(root->left,root->right);
        
    }
    
    bool dfs(TreeNode *left, TreeNode* right){
        if(left==NULL || right ==NULL){
            return left==right;
        }
        return (left->val==right->val) && dfs(left->left,right->right) && dfs(left->right,right->left);
        
    }
};