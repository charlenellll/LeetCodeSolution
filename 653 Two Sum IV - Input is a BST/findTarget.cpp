// unordered_map + DFS preorder recursion: O(n) time O(n) space
// 38 ms, 44%

class Solution {
private:
    unordered_set<int> record;
public:
    bool findTarget(TreeNode* root, int k) {
        if( !root ) return false;
        if( record.find(k - root->val) != record.end() ) return true;
        else{
            record.insert(root->val);
            return findTarget(root->left, k) || findTarget(root->right, k);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// for reference: BST Iterator's implementation(not by me): O(n) time O(log n) space

class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};
    bool hasNext() {
        return node != nullptr || !s.empty();
    }
    int next() {
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = s.top();
                s.pop();
                int nextVal = node->val;
                node = forward ? node->right : node->left;
                return nextVal;
            }
        }

        return -1;  // never reach & not necessary
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        for (int i = l.next(), j = r.next(); i < j;) {
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};

//Simplified using operator overloading

class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* node;
    bool forward;
    int cur;
public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) { (*this)++; };
    int operator*() { return cur; }
    void operator++(int) {
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = s.top();
                s.pop();
                cur = node->val;
                node = forward ? node->right : node->left;
                break;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        while (*l < *r) {
            if (*l + *r == k) return true;
            else if (*l + *r < k) l++;
            else r++;
        }
        return false;
    }
};