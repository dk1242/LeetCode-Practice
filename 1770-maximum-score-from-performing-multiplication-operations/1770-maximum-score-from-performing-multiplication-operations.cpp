class Solution {
public:
    // unordered_map<string, int>mp;
    // int dp[1000][1000];
    // int m, n;
    // int find(vector<int>&nums, vector<int>&multi, int si,  int j){
    //     // int n=nums.size(), m=multi.size();
    //     // cout<<j<<" "<<si<<" "<<ei<<"\n";
    //     if(j>=m){
    //         return 0;
    //     }
    //     // string key=to_string(si)+"_"+to_string(ei)+"_";
    //     // if(mp.find(key)!=mp.end()){
    //     //     return mp[key];
    //     // }
    //     if(dp[si][j]!=-1)
    //         return dp[si][j];
    //     // int ans=0;
    //     int start=find(nums, multi, si+1, j+1)+multi[j]*nums[si];
    //     int end=find(nums, multi, si, j+1)+multi[j]*nums[n-(j-si)-1];
    //     // ans+=max(start, end);
    //     // cout<<ans<<"\n";
    //     return dp[si][j]=max(start, end);
    // }
    // int maximumScore(vector<int>& nums, vector<int>& multi) {
    //     n=nums.size(), m=multi.size();
    //     int ans=0;
    //     memset(dp, -1, sizeof(dp));
    //     // vector<vector<int>>dp(1000, vector<int>(1000, -1));
    //     return find(nums, multi, 0, 0);
    // }
    int dp[1001][1001] = {};
int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
    if (i >= mults.size())
        return 0;
    if (!dp[l][i]) {
        int r = nums.size() - 1 - (i - l);
        dp[l][i] = max(nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1), 
            nums[r] * mults[i] + dfs(nums, mults, l, i + 1));
    }
    return dp[l][i];
}
int maximumScore(vector<int>& nums, vector<int>& mults) {
    int n=nums.size(), m=mults.size();
    for(int i=m-1;i>=0;i--){
        for(int l=i;l>=0;l--){
            int r=n-1-(i-l);
            dp[i][l]=max(nums[l]*mults[i]+dp[i+1][l+1], nums[r]*mults[i]+dp[i+1][l]);
        }
    }
    return dp[0][0];
}
};