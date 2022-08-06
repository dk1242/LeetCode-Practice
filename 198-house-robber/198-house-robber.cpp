class Solution {
public:
    int f(vector<int>&nums, int i, vector<int>&memo){
        if(i<0){
            return 0;
        }
        if(memo[i]!=-1)
            return memo[i];
        return memo[i]=max(nums[i]+f(nums, i-2, memo), f(nums, i-1, memo));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2, -1);
        // return f(nums, nums.size()-1, memo);
        int ans=0;
        dp[0]=0, dp[1]=nums[0];
        for(int i=2;i<=nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[nums.size()];
    }
};