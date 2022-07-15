class Solution {
public:
    int dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0){
            return 0;
        }
        vis[i][j]=1;
        return 1+dfs(grid, vis, i-1, j)+dfs(grid, vis, i+1, j)+dfs(grid, vis, i, j-1)+dfs(grid, vis, i, j+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int ans=0, curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // curr=0;
                if(grid[i][j]==1 && vis[i][j]!=1){
                    ans=max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};