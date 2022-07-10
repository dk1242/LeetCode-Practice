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
    unordered_map<int, vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>res;
        if(n%2==0)
            return res;
        if(n==1){
            res.push_back(new TreeNode(0));
            return res;
        }
        if(mp[n].size())return mp[n];
        n--;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>left=allPossibleFBT(i);
            vector<TreeNode*>right=allPossibleFBT(n-i);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *cur=new TreeNode(0);
                    cur->left=l;
                    cur->right=r;
                    res.push_back(cur);
                }
            }
        }
        return mp[n]=res;
    }
};