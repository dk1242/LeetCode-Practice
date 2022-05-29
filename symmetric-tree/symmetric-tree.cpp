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
    bool checkSymmetric(TreeNode* left, TreeNode* right){
        if(left==NULL || !right){
            return left==right;
        }
        if(left->val!=right->val)
            return false;
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return false;
        // return checkSymmetric(root->left, root->right);
        queue<TreeNode*>q1, q2;
        TreeNode* left, *right;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            left=q1.front();
            right=q2.front();
            q1.pop();
            q2.pop();
            if(left==NULL && right==NULL){
                continue;
                
            }
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
            
        }
        return true;
    }
};