class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        grid[0][0]=1;
        for(int i=1;i<n;i++)
            grid[i][0]=grid[i][0]==0 && grid[i-1][0]==1?1:0;
        for(int i=1;i<m;i++)
            grid[0][i]=grid[0][i]==0 && grid[0][i-1]==1?1:0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0)
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                else
                    grid[i][j]=0;
            }
        }
        return grid[n-1][m-1];
    }
};