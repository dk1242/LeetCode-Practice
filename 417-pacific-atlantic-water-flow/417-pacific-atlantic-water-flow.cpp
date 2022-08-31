class Solution {
public:
    void check(vector<vector<int>>& heights, int &f1, int &f2, int i, int j, vector<vector<int>>&vis){
        // cout<<i<<", "<<j<<" ";
        if(vis[i][j])
            return;
        if(i<0 || j<0){
            f1=1;
            return;
        }
        if(i>=heights.size() || j>=heights[0].size()){
            f2=1;
            return;
        }
        if(f1 && f2)
            return;
        vis[i][j]=1;
        if(i-1>=0 && heights[i-1][j]<=heights[i][j])
        check(heights, f1, f2, i-1, j, vis);
        else if(i-1<0)f1=1;
        
        if(j-1>=0 && heights[i][j-1]<=heights[i][j])
        check(heights, f1, f2, i, j-1, vis);
        else if(j-1<0)f1=1;
        
        if(i+1<heights.size() && heights[i+1][j]<=heights[i][j])
        check(heights, f1, f2, i+1, j, vis);
        else if(i+1>=heights.size())f2=1;
        
        if(j+1<heights[0].size() && heights[i][j+1]<=heights[i][j])
        check(heights, f1, f2, i, j+1, vis);
        else if(j+1>=heights[0].size())f2=1;
        vis[i][j]=0;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int f1=0, f2=0;
                check(heights, f1, f2, i, j, vis);
                if(f1==1 && f2==1){
                    ans.push_back({i,j});
                }
                // cout<<"\n";
            }
        }
        return ans;
    }
};