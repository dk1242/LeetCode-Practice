class Solution {
public:
    int dfs(int m, int n, int cr, int cc, int moves, vector<vector<vector<int>>>&dp){
        if(moves>=0 && (cr<0 || cr>=m || cc<0 || cc>=n))
            return 1;
        if(moves==0)
            return 0;
        if(dp[cr][cc][moves]!=-1)
            return dp[cr][cc][moves];
        return dp[cr][cc][moves]=(1ll*dfs(m, n, cr-1, cc, moves-1, dp)+1ll*dfs(m, n, cr+1, cc, moves-1, dp)+1ll*dfs(m, n, cr, cc-1, moves-1, dp)+1ll*dfs(m, n, cr, cc+1, moves-1, dp))%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return dfs(m, n, startRow, startColumn, maxMove, dp);
    }
};