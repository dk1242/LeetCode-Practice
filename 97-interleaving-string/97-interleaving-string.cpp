class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(), m=s2.length(), l=s3.length();
        if(n+m != l)
            return false;
        vector<vector<int>>vis(n+1, vector<int>(m+1, 0));
        queue<vector<int>>q;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it[0]==n && it[1]==m)return true;
            if(vis[it[0]][it[1]])continue;
            if(it[0]<n && s1[it[0]]==s3[it[0]+it[1]])
                q.push({it[0]+1, it[1]});
            if(it[1]<m && s2[it[1]]==s3[it[0]+it[1]])
                q.push({it[0], it[1]+1});
            vis[it[0]][it[1]]=1;
        }
        return false;
    }
};