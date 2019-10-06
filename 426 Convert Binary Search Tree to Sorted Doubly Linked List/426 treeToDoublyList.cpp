// 以下代码是否可以简化？
// 64 ms, faster than 94.19%
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if( !root ) return root;
        if( root && !root->left && !root->right ){
            root->left = root;
            root->right = root;
            return root;
        }
        Node* leftHead = treeToDoublyList(root->left);
        Node* rightHead = treeToDoublyList(root->right);
        Node* leftTail = NULL, *rightTail = NULL;
        if( leftHead ){
            leftTail = leftHead->left;
            leftTail->right = root;
            root->left = leftTail;
        }
        if( rightHead ){
            rightTail = rightHead->left;
            rightHead->left = root;
            root->right = rightHead;
        }
        //首尾相接
        if( leftHead && rightHead ){
            leftHead->left = rightTail; //rightHead存在则rightTail一定存在
            rightTail->right = leftHead;
        }
        else if( leftHead ){
            leftHead->left = root;
            root->right = leftHead;
        }
        else{
            root->left = rightTail;
            rightTail->right = root;
        }
        return (leftHead) ? leftHead : root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/