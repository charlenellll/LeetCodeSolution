//Simplified version
// 24 ms, faster than 95.96%
class Solution {
private:
    int initialValue = INT_MIN / 2;
    void maxPath( TreeNode* root, int& includeSingle, int& includeDouble, int& notInclude){//包含root有两种，单边/双边
        if( !root ) return;//在上层递归处理null情况
        if( !root->left && !root->right ){
            includeSingle = root->val;
            includeDouble = root->val;
            return;
        }
        
        int il = initialValue, idl = initialValue, nl = initialValue, ir = initialValue, idr = initialValue, nr = initialValue;
        maxPath( root->left, il, idl, nl);
        maxPath( root->right, ir, idr, nr);
        //需要分情况讨论，因为有负数，0不能用于比较大小
        notInclude = max(max(max(max(max( il, idl ), nl), ir), idr), nr);
        includeSingle = max(max(root->val, root->val + il), root->val + ir);
        includeDouble = root->val + il + ir;
    }
public:
    int maxPathSum(TreeNode* root) { //max(含root的最大值， 不含root的最大值)
        int include = initialValue, includeDouble = initialValue, notInclude = initialValue;
        maxPath( root, include, includeDouble, notInclude );
        return max(max(include, notInclude), includeDouble);
    }
};


// 28 ms
class Solution {
private:
    void maxPath( TreeNode* root, int& includeSingle, int& includeDouble, int& notInclude){//包含root有两种，单边/双边
        if( !root ) {
            includeSingle = INT_MIN / 2;
            includeDouble = INT_MIN / 2;
            notInclude = INT_MIN / 2;
            return;//在上层递归处理null情况
        }
        if( !root->left && !root->right ){
            includeSingle = root->val;
            includeDouble = root->val;
            notInclude = INT_MIN / 2;
            return;
        }
        
        int il = 0, idl = 0, nl = 0, ir = 0, idr = 0, nr = 0;
        maxPath( root->left, il, idl, nl);
        maxPath( root->right, ir, idr, nr);
        //需要分情况讨论，因为有负数，0不能用于比较大小
        notInclude = max(max(max(max(max( il, idl ), nl), ir), idr), nr);
        includeSingle = max(max(root->val, root->val + il), root->val + ir);
        includeDouble = root->val + il + ir;
    }
public:
    int maxPathSum(TreeNode* root) { //max(含root的最大值， 不含root的最大值)
        int include = 0, includeDouble = 0, notInclude = 0;
        maxPath( root, include, includeDouble, notInclude );
        return max(max(include, notInclude), includeDouble);
    }
};