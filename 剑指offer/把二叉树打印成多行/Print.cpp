// 运行时间：3ms 占用内存：492k
class Solution {
public:
        vector<vector<int> > Print(TreeNode* root) {
            vector<vector<int>> res;
            if( !root ) return res;
            queue<TreeNode*> q;
            q.push( root );
            vector<int> curLevel;
            while( !q.empty() ){
                curLevel.clear();
                int sz = q.size();//因为每次处理完了一层，q里剩下的是新的一层
                for(int i = 0; i < sz ; i++ ){
                    TreeNode* cur = q.front();
                    curLevel.push_back(cur->val);
                    q.pop();
                    if( cur->left ) q.push(cur->left);
                    if( cur->right ) q.push(cur->right);
                }
                res.push_back( curLevel );
            }
            return res;
        }
    
};

// 这样也可以，当然空间稍微大了一丢丢

class Solution {
public:
        vector<vector<int> > Print(TreeNode* root) {
            vector<vector<int>> res;
            if( !root ) return res;
            queue< pair<TreeNode*, int> > q;
            q.push( make_pair(root, 0) );
            while( !q.empty() ){
                TreeNode* cur = q.front().first;
                int level = q.front().second;
                q.pop();
                if( level == res.size() )
                    res.push_back(vector<int>());
                res[level].push_back(cur->val);
                if( cur->left ) q.push( make_pair(cur->left, level + 1) );
                if( cur->right ) q.push( make_pair(cur->right, level + 1));
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
};
*/