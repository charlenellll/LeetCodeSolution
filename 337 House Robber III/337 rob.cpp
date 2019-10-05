// 12 ms, faster than 93.10%
class Solution {
private:
    void rob(TreeNode* root, int& include, int& notInclude){
        if( !root ) return;//二者本来就是0
        if( !root->left && !root->right ){
            include = root->val;
            return;// notInclude = 0;
        }
        int il = 0, nl = 0, ir = 0, nr = 0;
        rob( root->left, il, nl);
        rob( root->right, ir, nr);
        notInclude = max(max(max(il + nr, ir + nl), il + ir), nl+nr); //不要省了nl+nr! 因为输入里有结点为0/这四种情况里有二者相等，这样具体选择谁会影响上层结构，所以nl+nr也是可以被单独选择的不一定和root一起！
        include = root->val + nl + nr;
    }
public:
    int rob(TreeNode* root) {
        int include = 0, notInclude = 0;
        rob( root, include, notInclude);
        return max(include, notInclude);
    }
};