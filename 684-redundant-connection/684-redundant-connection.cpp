class Solution {
public:
    void dfs(int &cycleStart, unordered_set<int>&cycle, unordered_map<int, vector<int>>&graph, vector<int>&vis, int cur, int par){
        if(vis[cur]){
            // cout<<cur;
            cycleStart=cur;
            return;
        }
        vis[cur]=1;
        // cout<<" "<<cur<<"@";
        for(auto child:graph[cur]){
            cout<<child;
            if(child==par)continue;
            if(cycle.empty())dfs(cycleStart, cycle, graph, vis, child, cur);
            if(cycleStart!=-1)
                cycle.insert(cur);
            if(cur == cycleStart) { cycleStart = -1; return; }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int, vector<int>>graph;
        vector<int>vis(n+1, 0);
        for(int i=0;i<n;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int cycleStart=-1;
        unordered_set<int>cycle;
        dfs(cycleStart, cycle, graph, vis, 1, -1);
        // cout<<1;
        // for(auto it:cycle)cout<<it;
        for(int i=n-1;i>=0;i--){
            if(cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
                return edges[i];
        }
        return { };
    }
};