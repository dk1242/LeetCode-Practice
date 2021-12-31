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
    int difference(TreeNode *root, int curMax, int curMin){
        if(root==NULL)
            return curMax-curMin;
        curMax=max(curMax, root->val);
        curMin=min(curMin, root->val);
        int left = difference(root->left, curMax, curMin);
        int right = difference(root->right, curMax, curMin);
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        return difference(root, root->val, root->val);
    }
    
};