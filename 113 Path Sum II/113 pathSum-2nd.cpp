// more concise version of solution 2
class Solution {
private:
    void pathSumVec(TreeNode* root, vector<vector<int>>& res, vector<int>& curPath, int sum){
        if( !root ) return;
        curPath.push_back( root->val );
        if( !root->left && !root->right && root->val == sum)
            res.push_back( curPath );
        pathSumVec(root->left, res, curPath, sum - root->val);
        pathSumVec(root->right, res, curPath, sum - root->val);
        curPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curPath;
        pathSumVec( root, res, curPath, sum);
        return res;
    }
};

// Solution 2: share the reference of global return vector and current path vector among recursions11
// 8 ms, faster than 96.71%
class Solution {
private:
    void pathSumVec(TreeNode* root, vector<vector<int>>& res, vector<int>& curPath, int sum){
        if( !root ) return;
        if( !root->left && !root->right ){
            if( root->val == sum ){
                curPath.push_back( sum );
                res.push_back( curPath );
                curPath.pop_back();
                return;
            }
            else return;
        }
        curPath.push_back( root->val );
        pathSumVec(root->left, res, curPath, sum - root->val);
        pathSumVec(root->right, res, curPath, sum - root->val);
        curPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> curPath;
        pathSumVec( root, res, curPath, sum);
        return res;
    }
};


// Solution 1: concatenate the return vector for left and right each time (Reeeeeeally slow!)
// 36 ms, faster than 5.31%
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if( !root ) return res;
        if( !root->left && !root->right ){
            if( root->val == sum )
                res.push_back( vector<int>(1, root->val) );
            return res;
        }
        vector<vector<int>> left = pathSum( root->left, sum - root->val);
        vector<vector<int>> right = pathSum( root->right, sum - root->val);
        for(auto item: left){
            vector<int> temp(1, root->val);
            for(auto num: item)
                temp.push_back( num );
            res.push_back(temp);
        }
        for(auto item: right){
            vector<int> temp(1, root->val);
            for(auto num: item)
                temp.push_back( num );
            res.push_back(temp);
        }
        return res;
    }
};