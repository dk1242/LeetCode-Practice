class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n, INT_MIN);
        dp[0]=nums[0];
        multiset<int>mst;
        mst.insert(dp[0]);
        for(int i=1;i<n;i++){
            if(i>k) mst.erase(mst.find(dp[i-k-1]));
            // if(i+k<n)cout<<dp[i+k];
            // for(auto it:mst)cout<<it<<" ";
            // cout<<"\n";
            dp[i]=*rbegin(mst)+nums[i];
            mst.insert(dp[i]);
            // int curr=INT_MIN;
            // for(int j=1;j<=k && i+j<n;j++){
            //     curr=max(dp[i+j], curr);
            // }
            // // cout<<dp[i]<<" ";
            // dp[i]+=nums[i]+curr;
            // // cout<<dp[i]<<"\n";
        }
        // for(auto it:dp)
        //     cout<<it<<" ";
        return dp.back();
    }
};