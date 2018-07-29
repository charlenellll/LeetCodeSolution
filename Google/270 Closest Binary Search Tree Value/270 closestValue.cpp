// 2. Iteration：在编译器不能做尾递归优化的情况下，还是应该将尾递归形式手动改成循环结构以提升性能
// 4 ms, beats 100%

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        TreeNode* curRoot = root;
        while( curRoot ){
            if( curRoot->val == target ) return curRoot->val;
            if( fabs(target-curRoot->val) < fabs(target-closest) ) closest = curRoot->val;
            if( target > curRoot->val ) curRoot = curRoot->right;
            else curRoot = curRoot->left; // 注意这里要小心curRoot经过上一行变成NULL的情况！！只能写else，不要写判断句！！
        }
        return closest;
    }
};

// 错误代码！！-------------------------------------------------------------------------------------
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        TreeNode* curRoot = root;
        while( curRoot ){
            if( curRoot->val == target ) return curRoot->val;
            if( fabs(target-curRoot->val) < fabs(target-closest) ) closest = curRoot->val;
            if( target > curRoot->val ) curRoot = curRoot->right;
            if( target < curRoot->val ) curRoot = curRoot->left; // 这里会报错！！！！！----------------------------
            // 实际上进入了上一个判断句后，curRoot变为了NULL！！！这里就会是非法访问！！！报错：member access within null pointer of type 'struct TreeNode'
        }
        return closest;
    }
};
//----------------------------------------------------------------------------------------------------------------


// 1. Recursion: sometimes slow
// 4 ms, beats 100%

class Solution {
private:
    int closest;
    void DFS(TreeNode* root, double target){
        if( root == NULL ) return;
        if( abs(closest - target) > abs(root->val - target) ) closest = root->val;
        if( target > root->val ) DFS(root->right, target);
        if( target < root->val ) DFS(root->left, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        if( root ) closest = root->val;
        DFS(root, target);
        return closest;
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
