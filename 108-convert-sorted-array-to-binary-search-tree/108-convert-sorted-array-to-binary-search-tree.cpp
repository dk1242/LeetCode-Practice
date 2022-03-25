/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * helper(vector<int>&nums, int low, int high){
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=helper(nums, low, mid-1);
        node->right=helper(nums, mid+1, high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return new TreeNode(nums[0]);
        if(n==2){
            TreeNode * root=new TreeNode(nums[0]);
            root->right=new TreeNode(nums[1]);
            return root;
        }
        TreeNode* root=helper(nums, 0, n-1);
        
        return root;
    }
};