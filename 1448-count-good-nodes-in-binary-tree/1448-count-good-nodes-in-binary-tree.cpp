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
    void count(TreeNode* root, int &ans, int maxm){
        if(root==NULL)
            return;
        if(root->val>=maxm){
            ans++;
            cout<<root->val<<" ";
            maxm=root->val;
        }
        count(root->left, ans, maxm);
        count(root->right, ans, maxm);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        count(root, ans, INT_MIN);
        return ans;
    }
};