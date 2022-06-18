class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, INT_MAX);
        dist[k]=0;
        for(int i=0;i<n;i++){
            for(auto it:times){
                int u=it[0], v=it[1], w=it[2];
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans, dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};