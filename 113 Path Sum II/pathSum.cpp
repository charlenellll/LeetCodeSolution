// My solution after optimized
// 12 ms
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> res;
        helper(root, sum, res, result);
        return result;
    }
    
    void helper(TreeNode* root, int target, vector<int>& res, vector<vector<int>>& result){
        if( root == NULL ) return;
        res.push_back( root->val );
        if( root->left == NULL && root->right == NULL && root->val == target )           
            result.push_back( res );
        helper( root->left, target - root->val, res, result );
        helper( root->right, target - root->val, res, result );
        res.pop_back();
    }
};


// 13ms
// This is the solution I used for linkedIn Machine Learning and Relevance Engineer Intern first round technical interview
// The interviewer said I could optimize it but I didn't see it where
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> res;
        helper(root, sum, res, result);
        return result;
    }
    
    void helper(TreeNode* root, int target, vector<int>& res, vector<vector<int>>& result){
        if( root == NULL ) return;
        if( root->left == NULL && root->right == NULL && root->val == target ){
            res.push_back( root->val );
            result.push_back( res );
            res.pop_back();
            return;
        }
        res.push_back( root->val );
        helper( root->left, target - root->val, res, result );
        helper( root->right, target - root->val, res, result );
        res.pop_back();
    }
};

// Maybe this is the lines of optimization he asked for?
// from Internet

class Solution {
 public:
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<vector<int>> res;
         vector<int> tmp; //保存中间结果
         tmpFunction(root, sum, tmp, res);
         return res;
     }
 
     void tmpFunction(TreeNode* root, int sum, vector<int> &tmp, vector<vector<int>>&res){
         if (root == NULL) return;
         tmp.push_back(root->val);
         if (root->left == NULL && root->right == NULL){
             if (root->val == sum)
                 res.push_back(tmp);
         }
         tmpFunction(root->left, sum - root->val, tmp, res);
         tmpFunction(root->right, sum - root->val, tmp, res);
         tmp.pop_back();
     }
 };



// sample 9ms code

struct PathSumContainer {
    vector<int> path;
    int runningSum;

    PathSumContainer() : path(), runningSum(0) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        PathSumContainer p;

        vector<vector<int>> results;

        this->pathSumRecurv(results, p, root, sum);

        return results;
    }

    void pathSumRecurv(vector<vector<int>>& results, PathSumContainer& p, TreeNode* node, int targetSum) {
        if (node == NULL) {
            return;
        }

        p.path.push_back(node->val);
        p.runningSum += node->val;

        // found it
        if (p.runningSum == targetSum && this->isLeaf(node)) {
            results.push_back(p.path);
        }

        this->pathSumRecurv(results, p, node->left, targetSum);
        this->pathSumRecurv(results, p, node->right, targetSum);

        p.path.pop_back();
        p.runningSum -= node->val;
    }

    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }
};