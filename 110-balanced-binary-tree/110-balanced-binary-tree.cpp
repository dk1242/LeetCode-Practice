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
    int check(TreeNode* root, int &ans){
        if(root==NULL)
            return 0;
        int lh=check(root->left, ans);
        int rh=check(root->right, ans);
        if(abs(lh-rh)>1){
            ans=0;
        }
        return max(lh, rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        int ans=1;
        check(root, ans);
        return ans;
    }
};