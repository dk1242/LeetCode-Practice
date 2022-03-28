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
    bool search(TreeNode* root, int k, unordered_set<int>&st){
        if(root==NULL)
            return false;
        if(st.count(k-root->val)){
            return true;
        }
        st.insert(root->val);
        return search(root->left, k, st)||search(root->right, k, st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return search(root, k, st);
    }
};