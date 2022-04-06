class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=1,c=0,n=nums.size();
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }else{
                auto ind=lower_bound(dp.begin(), dp.end(), nums[i]);
                dp[ind-dp.begin()]=nums[i];
            }
        }
        return dp.size();
    }
};