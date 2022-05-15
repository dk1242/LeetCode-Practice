class Solution {
public:
    unordered_map<string, int>mp;
    int totalPaths(vector<vector<int>>&grid, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || grid[i][j]!=0)
            return 0;
        string key="";
        key=to_string(i)+"-"+to_string(j);
        // cout<<key;
        if(mp[key])
            return mp[key];
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return mp[key]=1;
        grid[i][j]=1;
        int ans=totalPaths(grid, i+1, j)+totalPaths(grid, i, j+1);
        grid[i][j]=0;
        return mp[key]=ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m, vector<int>(n, 0));
        int ans=0;
        ans=totalPaths(grid, 0, 0);
        return ans;
    }
};