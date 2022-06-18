class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        dp[0]=grid[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    int ccost=dp[i-1][j]+grid[i][k]+cost[grid[i-1][j]][k];
                    dp[i][k]=min(dp[i][k], ccost);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};