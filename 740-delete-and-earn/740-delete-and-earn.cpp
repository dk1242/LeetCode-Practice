class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size(), m=*max_element(nums.begin(), nums.end());
        vector<int>dp(m+1, 0);
        for(int i=0;i<n;i++){
            dp[nums[i]]+=nums[i];
        }
        for(int i=2;i<=m;i++){
            dp[i]=max(dp[i-1], dp[i-2]+dp[i]);
        }
        return dp[m];
    }
};