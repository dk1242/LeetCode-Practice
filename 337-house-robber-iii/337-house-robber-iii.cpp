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
    unordered_map<TreeNode*, int>mp;
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(mp[root])
            return mp[root];
        int curr=0;
        if(root->left){
            curr+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            curr+=rob(root->right->left)+rob(root->right->right);
        }
        return mp[root]=max({root->val+curr, rob(root->left)+rob(root->right)});
    }
};