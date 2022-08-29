class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        map<int, vector<int>>g1, g2;
        vector<int>indeg1(k, 0), indeg2(k, 0);
        for(int i=0;i<rc.size();i++){
            g1[rc[i][0]-1].push_back(rc[i][1]-1);
            indeg1[rc[i][1]-1]++;
        }
        for(int i=0;i<cc.size();i++){
            g2[cc[i][0]-1].push_back(cc[i][1]-1);
            indeg2[cc[i][1]-1]++;
        }
        queue<int>q;
        vector<int>ord1;
        for(int i=0;i<indeg1.size();i++){
            if(indeg1[i]==0){
                q.push(i);
                ord1.push_back(i);
            }
        }
        while(!q.empty()){
            int it=q.front();
            q.pop();
            for(auto i:g1[it]){
                indeg1[i]--;
                if(indeg1[i]==0){
                    q.push(i);
                    ord1.push_back(i);
                }
            }
        }
        // for(auto it:ord1)
        //     cout<<it<<" ";
        vector<vector<int>>ans;
        if(ord1.size()!=k)
            return ans;
        
        vector<int>ord2;
        for(int i=0;i<indeg2.size();i++){
            if(indeg2[i]==0){
                // cout<<i<<"#";
                q.push(i);
                ord2.push_back(i);
            }
        }
        while(!q.empty()){
            int it=q.front();
            q.pop();
            for(auto i:g2[it]){
                indeg2[i]--;
                if(indeg2[i]==0){
                    q.push(i);
                    ord2.push_back(i);
                }
            }
        }
        if(ord2.size()!=k)
            return ans;
         // for(auto it:ord2)
         //    cout<<it<<" ";
        // cout<<"\n@";
        ans.resize(k, vector<int>(k, 0));
        map<int, vector<int>>mp;
        for(int i=0;i<k;i++){
            mp[ord1[i]].push_back(i);
        }
        for(int i=0;i<k;i++){
            mp[ord2[i]].push_back(i);
        }
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second[0]<<" "<<it.second[1]<<"\n";
            ans[it.second[0]][it.second[1]]=it.first+1;
        }
        return ans;
    }
};