/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// this struct is unnecessary in preorder traversal, HOWEVER
// inorder and postorder, unlike preorder traversal, need this struct to make all three traversal similar in the form
// or they will be really different
struct Command{
    string s; // go, print
    TreeNode* node;
    Command( string s, TreeNode* node): s(s), node(node){}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if( root == NULL )
            return res;
        
        stack<Command> stack;
        stack.push( Command("go", root) );
        while( !stack.empty() ){
            
            Command command = stack.top();
            stack.pop();
            
            if( command.s == "print" )
                res.push_back( command.node -> val );
            else{
                assert( command.s == "go" );
                // The order of commands we push into the stack should be the reverse order of the actual sequential implementation
                // Last-in, first-out.
                if( command.node-> right )
                    stack.push( Command("go",command.node->right) );
                if( command.node-> left )
                    stack.push( Command("go",command.node->left) );
                stack.push( Command("print",command.node) );
            }
        }
        
        return res;
    }
};


// Simplified version

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if( root ==  NULL) 
            return res;
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        while( !stack.empty() ){
            TreeNode* node = stack.top();
            stack.pop();
            
            if( node->right != NULL )
                stack.push( node->right );
            if( node->left != NULL )
                stack.push( node->left );
            res.push_back( node->val );
        }
        
        return res;
    }
};