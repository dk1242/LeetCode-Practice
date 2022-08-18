class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipies, vector<vector<string>>& ingd, vector<string>& supplies) {
        unordered_set<string>avail;
        unordered_map<string, vector<string>>g;
        for(int i=0;i<supplies.size();i++){
            avail.insert(supplies[i]);
        }
        unordered_map<string, int>indeg;
        for(int j=0;j<recipies.size();j++){
            for(int i=0;i<ingd[j].size();i++){
                if(avail.count(ingd[j][i])==0){
                    g[ingd[j][i]].push_back(recipies[j]);
                    indeg[recipies[j]]++;
                }
            }
        }
        queue<string>q;
        for(int i=0;i<recipies.size();i++){
            // cout<<indeg[recipies[i]]<<" ";
            if(indeg[recipies[i]]==0){
                q.push(recipies[i]);
            }
        }
        vector<string>ans;
        while(!q.empty()){
            string tmp=q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto it:g[tmp]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};