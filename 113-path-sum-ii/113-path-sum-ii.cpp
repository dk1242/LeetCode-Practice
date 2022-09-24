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
    void findPathSum(TreeNode* root, int targetSum, int currSum, vector<vector<int>>&res, vector<int>ans){
        if(root==NULL)
            return;
        if(!root->left && !root->right && currSum==targetSum){
            ans.push_back(root->val);
            res.push_back(ans);
            ans.clear();
            return;
        }
        ans.push_back(root->val);
        if(root->left){
            findPathSum(root->left, targetSum, currSum+root->left->val, res, ans);
        }
        if(root->right){
            findPathSum(root->right, targetSum, currSum+root->right->val, res, ans);
        }
        // return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        vector<int>ans;
       findPathSum(root, targetSum, root->val, res, ans);
        return res;
    }
};