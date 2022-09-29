class DSU{
public:
    vector<int>rank, par;
    DSU(int n){
        rank.resize(n, 1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int find(int x){
        if(x==par[x])
            return x;
        return par[x]=find(par[x]);
    }
    void merge(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y)
            return;
        if(rank[x]>rank[y])
            swap(x, y);
        rank[y]+=rank[x];
        par[x]=y;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        map<int, vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[vals[i]].push_back(i);
        }
        DSU dsu(n);
        int ans=n;
        vector<bool>vis(n, 0);
        for(auto it:mp){
            for(auto i:it.second){
                for(auto child:adj[i]){
                    if(vis[child])
                    dsu.merge(i, child);
                }
                vis[i]=1;
            }
            unordered_map<int, int>mp2;
            for(auto i:it.second){
                mp2[dsu.find(i)]++;
            }
            // sort(parent.begin(), parent.end());
            for(auto j:mp2){
                long long cnt=j.second;
                ans+=cnt*(cnt-1)/2;
            }
        }
        return ans;
    }
};