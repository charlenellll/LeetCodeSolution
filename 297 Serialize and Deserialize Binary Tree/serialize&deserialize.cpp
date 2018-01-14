// a better version that is less likely to make mistakes:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "#";
        
        string left = serialize( root->left ), right = serialize( root->right );
        return to_string( root->val ) + " " + left + " " + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return dfs(s);
    }
    
    TreeNode* dfs(istringstream& s){
        string data;
        s >> data;
        if( data == "#" ) return NULL;
        // In this case I have already checked if root is NULL
        TreeNode* root = new TreeNode( stoi(data) ), *left = dfs(s), *right = dfs(s);
        root->left = left, root->right = right;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


// My original code:
// I made two mistakes:

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "#";
        
        string left = serialize( root->left ), right = serialize( root->right );
        return to_string( root->val ) + " " + left + " " + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return dfs(s);
    }
    
    TreeNode* dfs(istringstream& s){
        string data;
        s >> data;
        TreeNode* root = create( data );
        // mistake 1: I forgot to check whether root is NULL, or it will lead to compile error
        // If I don't extract create as a function I could avoid it!
        if( root ){
            TreeNode *left = dfs(s), *right = dfs(s);
            root->left = left, root->right = right;
        }
        return root;
    }
    
    TreeNode* create(string data){
        if( data == "#") return NULL;
                                // mistake 2: -1 cannot be converted by "-1"-"0" because "-" doesn't support that
                                // need stoi()
        else return new TreeNode( stoi(data) );
    }
};