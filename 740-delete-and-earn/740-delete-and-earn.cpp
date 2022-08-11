class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(10002, 0);
        for(int i=0;i<n;i++){
            dp[nums[i]]+=nums[i];
        }
        for(int i=2;i<10002;i++){
            dp[i]=max(dp[i-1], dp[i-2]+dp[i]);
        }
        return dp[10001];
    }
};