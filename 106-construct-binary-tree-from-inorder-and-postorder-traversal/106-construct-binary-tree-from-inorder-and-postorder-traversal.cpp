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
    TreeNode* constructTree(vector<int>& postorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, map<int, int>&mp){
        if(iStart>iEnd || pStart>pEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pEnd]);
        int elem=mp[root->val];
        int nElem=elem-iStart;
        root->right=constructTree(postorder, pStart+nElem, pEnd-1, inorder, elem+1, iEnd, mp);
        root->left=constructTree(postorder, pStart, pStart+nElem-1, inorder, iStart, elem-1, mp);
        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pStart=0, pEnd=postorder.size()-1, iStart=0, iEnd=inorder.size()-1;
        map<int, int>mp;
        for(int i=0;i<iEnd+1;i++){
            mp[inorder[i]]=i;
        }
        return constructTree(postorder, pStart, pEnd, inorder, iStart, iEnd, mp);
    }
};