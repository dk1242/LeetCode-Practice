class Solution {
public:
    int sum2d(vector<vector<int>> &p, int r1, int c1, int r2, int c2) {
        return p[c2 + 1][r2 + 1] + p[c1][r1] - p[c1][r2 + 1] - p[c2 + 1][r1];
    }
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>stamp(n, vector<int>(m, 0));
        vector<vector<int>> pref1(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            pref1[i + 1][j + 1] = grid[i][j] + pref1[i + 1][j] + pref1[i][j + 1] - pref1[i][j];
        for(int i=h-1;i<n;i++){
            for(int j=w-1;j<m;j++){
                if(sum2d(pref1, j-w+1, i-h+1, j, i)==0)
                    stamp[i][j]=1;
            }
        }
        vector<vector<int>> pref2(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            pref2[i + 1][j + 1] = stamp[i][j] + pref2[i + 1][j] + pref2[i][j + 1] - pref2[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 0 && sum2d(pref2, j, i, min(m - 1, j + w - 1), min(n- 1, i + h - 1)) == 0)
                return false;
    
    return true;
    }
};