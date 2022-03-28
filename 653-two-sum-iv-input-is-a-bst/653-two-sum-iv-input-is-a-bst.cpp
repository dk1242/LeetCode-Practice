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
    bool dfs(TreeNode* root, int k, TreeNode* cur){
        if(cur==NULL)
            return false;
        return search(root, k-cur->val, cur) || dfs(root, k, cur->left) || dfs(root, k, cur->right);
    }
    bool search(TreeNode* root, int val, TreeNode* cur){
        if(root==NULL)
            return false;
        return (root->val == val) && (root != cur) 
            || (root->val < val) && search(root->right,val, cur) 
                || (root->val > val) && search(root->left, val, cur);
    }
    bool findTarget(TreeNode* root, int k) {
        // unordered_set<int>st;
        return dfs(root, k, root);
    }
};