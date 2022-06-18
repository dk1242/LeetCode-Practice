class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mapp) {
        int n=s.length(), k=sub.length();
        // unordered_map<char, unordered_set<char>>mp;
        // for(int i=0;i<mapp.size();i++){
        //     mp[mapp[i][0]].insert(mapp[i][1]);
        // }
        int mp[256][256]={};
        for(int i=0;i<256;i++){
            mp[i][i]=1;
        }
        for(int i=0;i<mapp.size();i++){
            mp[mapp[i][0]][mapp[i][1]]=1;
        }
        for(int i=0;i<=n-k;i++){
            int f=0;
            for(int j=0;j<k;j++){
                char x=s[i+j], y=sub[j];
                if(x==y || mp[y][x])
                    continue;
                else{
                    f=1;
                    break;
                }
            }
            if(f==0)
                return true;
        }
        return false;
    }
};