class Solution {
public:
    void dfs(unordered_map<string, double>&mp, unordered_map<string, vector<string>>&graph, double &val, map<string, int>&vis, bool &found, string &start, string &end){
        vis[start]=1;
        if(found)
            return;
        for(auto child:graph[start]){
            if(vis[child]!=1){
                val*=mp[start+"->"+child];
                if(end==child){
                    found=true;
                    return;
                }
                dfs(mp, graph,val, vis, found, child, end);
                if(found)
                    return;
                else val/=mp[start+"->"+child];
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& val, vector<vector<string>>& quer) {
        int n=eqs.size();
        vector<double>ans(quer.size());
        unordered_map<string, double>mp;
        unordered_map<string, vector<string>>graph;
        
        for(int i=0;i<n;i++){
            string u=eqs[i][0];
            string v=eqs[i][1];
            mp[u+"->"+v]=val[i];
            mp[v+"->"+u]=1.0/val[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<quer.size();i++){
            string start=quer[i][0];
            string end=quer[i][1];
            if(graph[start].size()==0 || !graph[end].size())
                ans[i]=-1;
            else{
                double val=1.0;
                map<string, int>vis;
                bool found=false;
                if(start==end)
                    found=true;
                else{
                    dfs(mp, graph, val, vis, found, start, end);
                }
                if(found==true)
                    ans[i]=val;
                else ans[i]=-1;
            }
        }
        return ans;
    }
};