// class Solution {
// public:
//     int time=1;
//     void dfs(int curr, int prev, vector<int>&disc, vector<int>&low, unordered_map<int, vector<int>>&graph, vector<vector<int>>&ans){
//         disc[curr]=low[curr]=time++;
//         for(auto next:graph[curr]){
//             if(disc[next]==0){
//                 dfs(next, curr, disc, low, graph, ans);
//                 low[curr]=min(low[curr], low[next]);
//             }else if(next!=prev){
//                 low[curr]=min(low[curr], disc[next]);
//             }else if(low[next]>disc[curr]){
//                 cout<<curr<<next;
//                 ans.push_back({curr, next});
//             }
//         }
//     }
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//         vector<int>disc(n,0);
//         vector<int>low(n, 0);
//         vector<vector<int>>ans;
//         unordered_map<int, vector<int>>graph;
//         for(auto it:connections){
//             graph[it[0]].push_back(it[1]);
//             graph[it[1]].push_back(it[0]);
//         }
//         dfs(0, -1, disc, low, graph, ans);
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc = vector<int>(n,0);
        low = vector<int>(n, 0);
        vector<vector<int>> ans;
        for (auto conn : connections) {
            edgeMap[conn[0]].push_back(conn[1]);
            edgeMap[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1, ans);
        return ans;
    }
    void dfs(int curr, int prev, vector<vector<int>> &ans) {
        disc[curr] = low[curr] = time++;
        for (int next : edgeMap[curr]) {
            if (disc[next] == 0) {
                dfs(next, curr, ans);
                low[curr] = min(low[curr], low[next]);
            } else if (next != prev)
                low[curr] = min(low[curr], disc[next]);
            if (low[next] > disc[curr]) 
                ans.push_back({curr, next});
        }
    }
private:
    vector<int> disc, low;
    int time = 1;
    unordered_map<int, vector<int>> edgeMap;
};