class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(grid[0][0] || grid[n-1][m-1])
            return -1;
        queue<pair<int, int>>q;
        q.push({0,0});
        vector<pair<int, int>>dir={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        grid[0][0]=1;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first, y=curr.second;
            // cout<<grid[x][y]<<" ";
            if(x==n-1 && y==m-1)
                return grid[x][y];
            for(auto it:dir){
                
                int nx=x+it.first, ny=y+it.second;
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                    // cout<<nx<<ny<<" ";
                    q.push({nx, ny});
                    grid[nx][ny]=grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};