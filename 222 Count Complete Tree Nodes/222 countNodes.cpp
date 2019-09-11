// Solution 2 - Save time for complete subtrees
// 28 ms, faster than 91.61%
class Solution {
public:
    int countNodes(TreeNode* root) {
        if( !root )
            return 0;
        int l = 0, r = 0;
        TreeNode* left = root, *right = root;
        while(left){
            l++;
            left = left->left;
        }
        while(right){
            r++;
            right = right->right;
        }
        if( l == r )
            return pow(2,l)-1;
        else
            return countNodes(root->left) + 1 + countNodes(root->right);
    }
};


// Solution 1 - DFS, brutal force
// Runtime: 28 ms, faster than 91.61% ; Memory Usage: 28.5 MB, less than 100.00%

class Solution {
public:
    int countNodes(TreeNode* root) {
        if( !root )
            return 0;
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};