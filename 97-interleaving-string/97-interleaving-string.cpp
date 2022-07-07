class Solution {
public:
    bool dfs(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>&dp){
        if(i<0 && j<0 && k<0)
            return true;
        if(i>=0 && j>=0 && dp[i][j]!=-1)
            return dp[i][j];
        if(i>=0 && s1[i]==s3[k] && j>=0 && s2[j]==s3[k])
            return dp[i][j]=dfs(s1, s2, s3, i-1, j, k-1, dp) | dfs(s1, s2, s3, i, j-1, k-1, dp);
        else if(i>=0 && s1[i]==s3[k])
            return dfs(s1, s2, s3, i-1, j, k-1, dp);
        else if(j>=0 && s2[j]==s3[k])
            return dfs(s1, s2, s3, i, j-1, k-1, dp);
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(), m=s2.length(), l=s3.length();
        if(n+m != l)
            return false;
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return dfs(s1, s2, s3, n-1, m-1, l-1, dp);
    }
};