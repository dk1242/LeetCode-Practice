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
class Solution
{
public:
    // void inorder(TreeNode* root, vector<int>&res){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int>res;
        stack<TreeNode*>st;
        TreeNode *cur=root;
        while(!st.empty() || cur){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            res.push_back(cur->val);
            cur=cur->right;
        }
        return res;
    // vector<int> res;
    // TreeNode *curr = root;
    // while (curr)
    // {
    //     if (curr->left == NULL)
    //     {
    //         res.push_back(curr->val);
    //         curr = curr->right;
    //     }
    //     else
    //     {
    //         TreeNode *prev = curr->left;
    //         while (prev->right && prev->right != curr)
    //         {
    //             prev = prev->right;
    //         }
    //         if (prev->right == NULL)
    //         {
    //             prev->right = curr;
    //             curr = curr->left;
    //         }
    //         else
    //         {
    //             prev->right = NULL;
    //             res.push_back(curr->val);
    //             curr = curr->right;
    //         }
    //     }
    // }
    // return res;
    }
};