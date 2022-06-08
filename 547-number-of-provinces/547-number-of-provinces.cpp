class Solution {
public:
    void dfs(vector<int>&vis, int i, vector<vector<int>>&isConn){
        for(int j=0;j<isConn.size();j++){
            if(isConn[i][j]==1 && vis[j]==0){
                vis[j]=1;
                dfs(vis, j, isConn);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0,n=isConnected.size();
        vector<int>vis(n, 0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(vis, i, isConnected);
                ans++;
            }
        }
        return ans;
    }
};