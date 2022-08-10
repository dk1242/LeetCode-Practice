class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        int n=ques.size();
        long long ans=0;
        vector<long long>dp(n+1, 0);
//         for(int i=0;i<n;i++){
//             int skip=ques[i][1];
//             if(i-1>=0 && i-skip-1>=0){
//                 dp[i]=max(dp[i-1], 0LL+ques[i][0]+dp[i-skip-1]);
//                 // cout<<i+skip+1<<" ";
                
//             }
//             cout<<dp[i]<<" ";
//             // ans=max(ans, dp[i]);
//         }
        for(int i=n-1; i>=0; i--){
            dp[i]=max(dp[i+1], ques[i][0]+dp[min(i+ques[i][1]+1, n)]);
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};