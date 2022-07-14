class Solution {
public:
    bool dfs(vector<int>&nums, vector<vector<int>>&dp, int ind, int target){
        if(target==0)
            return true;
        if(ind==0 || target<0)
            return false;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        return dp[ind][target]=dfs(nums, dp, ind-1, target-nums[ind-1])||dfs(nums, dp, ind-1, target);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        vector<vector<int>>dp(n+1, vector<int>(sum/2+1, -1));
        return dfs(nums, dp, n-1, sum/2);
    }
};