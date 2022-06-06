class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int>dir={0,1,0,-1,0};
        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        dp[0][0]=0;
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto it=dq.front();
            dq.pop_front();
            int i=it.first, j=it.second;
            for(int k=0;k<4;k++){
                int x=i+dir[k], y=j+dir[k+1];
                if (x == (m-1) && y == (n-1)) {
                        return dp[i][j];
                }
                if(x<0 || y<0 || x>=n || y>=m)continue;
                if(!vis[x][y]){
                    dp[x][y]=dp[i][j]+(grid[x][y]==1);
                    if(grid[x][y]==1){
                        dq.push_back({x,y});
                    }else dq.push_front({x, y});
                    vis[x][y]=1;
                }
            }
        }
        return dp[n-1][m-1];
    }
};