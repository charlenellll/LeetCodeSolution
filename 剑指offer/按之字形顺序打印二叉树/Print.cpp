// 运行时间：4ms 占用内存：492k
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {// BFS
        vector<vector<int>> res;
        if( !root ) return res;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 1));
        vector<int> levelSeq;
        int procLevel = 0, level = 0;//处理中的level（还没存）和当前结点level
        while( !q.empty() ){
            TreeNode* cur = q.front().first;
            level = q.front().second;
            q.pop();
            if( cur->left ) q.push(make_pair(cur->left, level + 1));
            if( cur->right ) q.push(make_pair(cur->right, level + 1));
            // 打印
            if( level > 1 && level > procLevel ){//到达新一层时将上一层添加至返回结果里,从新节点level=2开始
                if( (level - 1) % 2 == 0 )// 存level-1层
                    reverse( levelSeq.begin(), levelSeq.end() );//双数层从右至左
                res.push_back( levelSeq );
                levelSeq.clear();
                procLevel = level;
            }
            levelSeq.push_back( cur->val );
        }
        if( levelSeq.size() != 0 ){//如果想把这部分收进while循环内部的话需要加一个for循环：for( int i = 0; i < sz; i++ ){} 每次直接把一层操作完;当然sz = q.size()
            if( level % 2 == 0 ) reverse(levelSeq.begin(), levelSeq.end() );//存最后的level层
            res.push_back( levelSeq );
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