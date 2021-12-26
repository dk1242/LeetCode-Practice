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
    TreeNode* arrayToTree(vector<int>& preorder, map<int, int> &mp, int left, int right, int &pIndex){
        if(left>right || pIndex>=preorder.size())
            return NULL;
        
        int rootVal=preorder[pIndex++];
        TreeNode *root = new TreeNode(rootVal);
        root->left=arrayToTree(preorder, mp, left, mp[rootVal]-1, pIndex);
        root->right=arrayToTree(preorder, mp, mp[rootVal]+1, right, pIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pIndex=0;
        map<int, int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return arrayToTree(preorder, mp, 0, n-1, pIndex);
    }
};