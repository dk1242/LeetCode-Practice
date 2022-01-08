class Solution {
public:
    int dp(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>&mem){
        if(col1<0 || col1>=grid[0].size() || col2<0 || col2>=grid[0].size()){
            return 0;
        }
        if(mem[row][col1][col2]!=-1)
            return mem[row][col1][col2];
        int res=0;
        res+=grid[row][col1];
        if(col1!=col2)
            res+=grid[row][col2];
        if(row!=grid.size()-1){
            int maax=0;
            for(int c1=col1-1;c1<=col1+1;c1++){
                for(int c2=col2-1;c2<=col2+1;c2++){
                    maax=max(maax, dp(row+1, c1, c2, grid, mem));
                }
            }
            res+=maax;
        }
       mem[row][col1][col2]=res;
       return res; 
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>>mem(n, vector(m, vector(m, -1)));
        return dp(0, 0, m-1, grid, mem);
    }
};