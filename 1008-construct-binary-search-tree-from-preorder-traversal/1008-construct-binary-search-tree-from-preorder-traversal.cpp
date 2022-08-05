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
    TreeNode* bstFormed(vector<int>&preorder, int &ind, int limit){
        if(ind==preorder.size() || preorder[ind]>limit){
            return NULL;
        }
        TreeNode * root=new TreeNode(preorder[ind++]);
        
            root->left=bstFormed(preorder, ind, root->val);
          
            root->right=bstFormed(preorder, ind, limit);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int limit=INT_MAX;
        int i=0;
        return bstFormed(preorder, i, limit);
    }
};