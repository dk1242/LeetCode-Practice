class Solution {
public:
    int n,m;
    int count(vector<vector<int>>& grid, int i, int j, int sum, int k, vector<vector<vector<int>>>&dp){
        if(i>=n || j>=m)
            return 0;
        if(i==n-1 && j==m-1){
            return ((sum+grid[n-1][m-1])%k==0);
        }
        if(dp[i][j][sum%k]!=-1)
            return dp[i][j][sum%k];
        int ans=count(grid, i+1, j, sum+grid[i][j], k, dp)+count(grid, i, j+1, sum+grid[i][j], k, dp);
        return dp[i][j][sum%k]=ans%1000000007;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return count(grid, 0,0, 0, k, dp);
    }
};