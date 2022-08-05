class Solution {
public:
    int ans=0;
    int countAns(vector<int>&nums, int target, vector<int>&dp){
        if(target==0)return 1;
        if(dp[target]!=-1)
            return dp[target];
        dp[target]=0;
        for(auto it:nums){
            if(it<=target)
                dp[target]+=countAns(nums, target-it, dp);
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, -1);
        return countAns(nums, target, dp);
        // return dp[0];
    }
};