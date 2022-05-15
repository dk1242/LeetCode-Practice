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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return 1+max(height(root->left), height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int l=height(root);
        queue<TreeNode*>q;
        q.push(root);
        map<int, int>mp;
        int c=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                
                TreeNode* temp=q.front();
                q.pop();
                mp[c]+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            c++;
        }
        return mp[l-1];
    }
};