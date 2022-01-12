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
    void sum(TreeNode *root, int &ans, string &s){
        if(root==NULL){
            cout<<s<<" ";
            if(s!="")
                ans+=stoi(s, 0, 2);
            return;
        }
        if(root->left==NULL && root->right==NULL){
            cout<<s<<"@ ";
            
                s+=to_string(root->val);
                ans+=stoi(s, 0, 2);
                s.pop_back();
            
            return;
        }
        s+=to_string(root->val);
        if(root->left)
        sum(root->left, ans, s);
        if(root->right)
        sum(root->right, ans, s);
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0; string s="";
        sum(root, ans, s);
        return ans;
    }
};