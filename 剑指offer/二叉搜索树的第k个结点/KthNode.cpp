// 运行时间：4ms 占用内存：484k
class Solution {
private:
    int nodeCount(TreeNode* root){
        if( !root ) return 0;
        return nodeCount(root->left) + nodeCount(root->right) + 1;
    }
public:
    TreeNode* KthNode(TreeNode* root, int k){
        if( !root || k == 0 ) return nullptr; 
        int leftCnt = nodeCount(root->left);
        if( k == leftCnt+1 ) return root;
        else if( k > leftCnt+1 ) return KthNode(root->right, k-leftCnt-1);
        else return KthNode( root->left, k );
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