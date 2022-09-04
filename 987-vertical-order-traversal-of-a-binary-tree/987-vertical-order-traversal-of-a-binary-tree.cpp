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
    void dfs(TreeNode* node, map<int,map<int, multiset<int>>>&mp, int hd, int ht){
      if(node==NULL){
          return;
      }
      mp[hd][ht].insert(node->val);
      if(node->left)
      dfs(node->left, mp, hd-1, ht+1);
      if(node->right)
      dfs(node->right, mp, hd+1, ht+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        vector<vector<int>>res;
        int count=0;
        dfs(root, mp,0, count);
        for(auto it:mp){
            // cout<<it.first<<" ";
            vector<int>col;
            for(auto p:it.second){
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};