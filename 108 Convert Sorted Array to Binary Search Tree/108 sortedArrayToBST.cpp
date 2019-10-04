// 16 ms, faster than 86.47%
class Solution {
private:
    TreeNode* arrayToBST(vector<int>& nums, int l, int r){
        if( l > r ) return NULL;
        int mid = l + (r - l)/2; //to prevent overflow
        TreeNode* root = new TreeNode(nums[mid]); //includes l==r condition
        root->left = arrayToBST(nums, l, mid-1);
        root->right = arrayToBST(nums, mid+1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size()-1);
    }
};