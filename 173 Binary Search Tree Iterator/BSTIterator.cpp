/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> record;
public:
    BSTIterator(TreeNode *root) {
        while( root ){
            record.push( root );
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !record.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = record.top();
        record.pop();
        int small = node->val;
        node = node->right;
        while( node ){
            record.push( node );
            node = node->left;
        } 
        return small;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


// although this can pass OJ, the space complexity does not meet the requirement of O(height)

class BSTIterator {
private:
    queue<int> inOrderNodes;
                                // the mistake I made here! I need to pass in &q, not q if i want q be global
    void inOrder(TreeNode* root, queue<int>& q){
        if( !root ) return;
        if( root->left ) inOrder(root->left, q);
        q.push( root->val );
        if( root->right ) inOrder(root->right, q);
        return;
    }
public:
    BSTIterator(TreeNode *root) {
        inOrder( root, inOrderNodes);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !inOrderNodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        int smallest = inOrderNodes.front();
        inOrderNodes.pop();
        return smallest;
    }
};