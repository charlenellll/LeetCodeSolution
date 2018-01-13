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
    int findSecondMin(TreeNode* root, int minVal){
        
        if( !root ) return -1;
        if( root->val != minVal ) return root->val;
        
        // root->val == minVal, get the smaller one of its subtrees' second min value
        int left = findSecondMin(root->left, minVal), right = findSecondMin(root->right, minVal);
        // if they both are not -1 (that they have found second smallest value other than minVal), choose the smaller one
        if( left != -1 && right != -1 ) return min(left, right);
        // if any of them is -1, get the larger value; if all the subtrees equal to minVal, it will return -1
        else return max(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {   
        return findSecondMin(root, root->val);
    }
};
// 3 ms


// I changed my code according to the fastest code:
// 2 ms now

class Solution {
private:
    int findSecondMin(TreeNode* root, int minVal){
        
        if( !root ) return -1;
        if( root->val != minVal ) return root->val;
        
        // root->val == minVal, get the smaller one of its subtrees' second min value
        int left = findSecondMin(root->left, minVal), right = findSecondMin(root->right, minVal);
        // return ( left != -1 && right != -1 )? min(left, right) : max(left, right);
        if( left == -1 ) return right;
        if( right == -1 ) return left;
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {  
        if( !root ) return -1;
        return findSecondMin(root, root->val);
    }
};


// fastest solution: pretty much the same

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int ans = minval(root, root->val);
        return ans;
    }
    
    int minval(TreeNode* p, int first) {
        if (p == nullptr) return -1;
        if (p->val != first) return p->val;
        int left = minval(p->left, first), right = minval(p->right, first);
        // if all nodes of a subtree = root->val, 
        // there is no second minimum value, return -1
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};