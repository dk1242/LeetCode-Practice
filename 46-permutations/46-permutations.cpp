class Solution {
public:
    void backtrack(vector<vector<int>>&res, vector<int>&res1, vector<int>&nums, int n, int start, vector<int> &vis){
        if(res1.size()==n){
            res.push_back(res1);
            return;
        }
        for(int i=0;i<n;i++){
            // auto it=find(res1.begin(), res1.end(), nums[i]);
            // if(it != res1.end())continue;
            if(vis[i])continue;
            res1.push_back(nums[i]);
            vis[i]=1;
            backtrack(res, res1, nums, n, i+1, vis);
            vis[i]=0;
            res1.pop_back();   
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>res1;
        int n=nums.size();
        vector<int>vis(n, 0);
        backtrack(res, res1, nums, n, 0, vis);
        return res;
    }
};