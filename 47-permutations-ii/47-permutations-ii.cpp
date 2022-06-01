class Solution {
public:
    unordered_map<int,int>mp;
    void backtrack(vector<vector<int>>&res, vector<int>&res1, vector<int>&nums, int n, int start){
        if(start==n){
            res.push_back(res1);
            return;
        }
        for(auto &it:mp){
            int num=it.first, count=it.second;
            if(count==0)continue;
            res1.push_back(num);
            mp[num]--;
            backtrack(res,res1, nums, n, start+1);
            res1.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>res1;
        vector<vector<int>>res;
        int n=nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]++;
        backtrack(res, res1, nums, n, 0);
        return res;
    }
};