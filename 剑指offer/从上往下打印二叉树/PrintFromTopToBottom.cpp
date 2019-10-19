// 运行时间：4ms 占用内存：488k
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) { // BFS
        vector<int> res;
        if( !root ) return res;
        queue<TreeNode*> q;
        q.push( root );
        while( !q.empty() ){
            TreeNode* cur = q.front();
            q.pop();
            res.push_back( cur->val );
            if( cur->left ) q.push( cur->left );
            if( cur->right ) q.push( cur->right );
        }
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