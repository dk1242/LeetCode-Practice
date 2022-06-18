class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<int>q;
        unordered_map<int, vector<pair<int, int>>>graph;
        for(auto it:times){
            graph[it[0]].push_back({it[1], it[2]});
        }
        q.push(k);
        vector<int>dist(n+1, INT_MAX);
        dist[k]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto [v, w]:graph[u]){
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    q.push(v);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(auto it:times){
        //         int u=it[0], v=it[1], w=it[2];
        //         if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
        //             dist[v]=dist[u]+w;
        //         }
        //     }
        // }
        // for(auto it:dist)
        //     cout<<it<<" ";
        // cout<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans, dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};