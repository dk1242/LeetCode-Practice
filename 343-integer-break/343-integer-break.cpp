class Solution {
public:
    int integerBreak(int n) {
        // vector<int>dp(n+1, 0);
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     for(int j=1;j<=i/2;j++){
        //         dp[i]=max(dp[i], max(dp[j], j)*max(i-j, dp[i-j]));
        //     }
        // }
        // return dp[n];
        if(n==2)
            return 1;
        else if(n==3)
            return 2;
        if(n%3==0)
            return pow(3, n/3);
        else if(n%3==1)
            return 2*2*pow(3, (n-4)/3);
        else
            return 2*pow(3, n/3);
        
    }
};