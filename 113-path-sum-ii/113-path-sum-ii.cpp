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
    void findPathSum(TreeNode* root, int targetSum, int currSum, vector<vector<int>>&res, vector<int>&ans){
        if(root==NULL)
            return ;
        ans.push_back(root->val);
        if(!root->left && !root->right && currSum+root->val==targetSum){
            res.push_back(ans);
            
        }
        findPathSum(root->left, targetSum, currSum+root->val, res, ans);
        findPathSum(root->right, targetSum, currSum+root->val, res, ans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        vector<int>ans;
        findPathSum(root, targetSum, 0, res, ans);
        return res;
    }
};