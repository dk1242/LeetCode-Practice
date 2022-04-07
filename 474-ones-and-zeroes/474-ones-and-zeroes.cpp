class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(auto str: strs){
            int ones=0, zero=0;
            for(auto s:str){
                if(s=='0')
                    zero++;
                else ones++;
            }
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j], 1+dp[i-zero][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};