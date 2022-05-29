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
    void postorder(TreeNode* root, vector<int>&res){
        if(root==NULL)
            return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    // if (root == NULL){
    //     return res;
    // }
    // stack<TreeNode *> st;
    // st.push(root);
    // while (!st.empty())
    // {
    //     TreeNode *curr = st.top();
    //     st.pop();
    //     if (curr->left)
    //     {
    //         st.push(curr->left);
    //     }
    //     if (curr->right)
    //     {
    //         st.push(curr->right);
    //     }
    //     res.push_back(curr->val);
    // }
    // return res;
    }
};