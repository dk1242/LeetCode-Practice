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
class Node{
    public:
    int maxV, minV, sum;
    Node(int minV, int maxV, int sum){
        this->minV=minV;
        this->maxV=maxV;
        this->sum=sum;
    }
};
class Solution {
public:
    vector<int>maxSumInBST(TreeNode* root){
        if(root==NULL){
            return {1, INT_MIN, INT_MAX, 0};
        }
        auto left=maxSumInBST(root->left);
        auto right=maxSumInBST(root->right);
        bool isBST=left[0] && right[0] && left[1]<root->val && right[2]>root->val;
        int sum=root->val+left[3]+right[3];
        if(isBST){
            ans=max(ans, sum);
        }
        return {isBST?1:0, max(root->val, right[1]), min(root->val, left[2]), sum};
    }
    int ans=0;
    int maxSumBST(TreeNode* root) {
        
        maxSumInBST(root);
        return ans;
    }
};