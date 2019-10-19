// 运行时间：4ms 占用内存：500k
class Solution {
private:
    void find(TreeNode* root, int target, vector<int>& curPath, vector<vector<int>>& res){
        if( !root ) return;
        curPath.push_back( root->val );
        if( !root->left && !root->right && root->val == target )//递归到底且符合条件时加入res
            res.push_back( curPath );
        else{
            find( root->left, target - root->val, curPath, res);
            find( root->right, target - root->val, curPath, res);
        }
        curPath.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> cur;
        vector<vector<int>> res;
        find(root, expectNumber, cur, res);
        return res;
    }
};

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/