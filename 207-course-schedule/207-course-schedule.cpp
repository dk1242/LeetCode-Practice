class Solution {
public:
    // bool checkCycle(int i, int V, vector<int>adj[], vector<int>&vis){
    //     queue<pair<int, int>>q;
    //     vis[i]=1;
    //     q.push({i, -1});
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         int par=q.front().second;
    //         q.pop();
    //         for(auto it:adj[node]){
    //             if(!vis[it]){
    //                 vis[it]=1;
    //                 q.push({it, node});
    //             }else{
    //                 if(par!=it)
    //                     return  true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool canFinish(int n, vector<vector<int>>& edges) {
    map<int, vector<int>>adj;
    queue<int>q;
    vector<int>indeg(n, 0);
        int u,v, e=edges.size();
//     cout<<e<<m<<n;
        for(int i=0;i<e;i++){
            u=edges[i][0];
            v=edges[i][1];
//             cout<<u<<v;
            adj[u].push_back(v);
            indeg[v]++;
//             adj[v].push_back(u);
        }
    for(int i=0;i<n;i++){
        if(indeg[i]==0)
            q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return cnt==n;
    }
};