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
    bool isValid(TreeNode* root, long long minv, long long maxv){
        if(root==NULL)
            return true;
        if((root->val>=maxv) || (root->val<=minv))
            return false;
        return isValid(root->left, minv, root->val) && isValid(root->right, root->val, maxv);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, 2ll*INT_MIN, 2ll*INT_MAX);
    }
};