class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string t) {
        vector<string>ans;
        for(auto s:words){
            int flag1=1, flag2=1;
            map<char, char>mp;
            int n=s.length();
            for(int i=0;i<n;i++){
                if(mp.find(s[i])!=mp.end()){
                // cout<<mp[s[i]]<<t[i];
                    if(mp[s[i]]!=t[i])
                    {
                        flag1=0;
                        break;
                    }
                }
                mp[s[i]]=t[i];
                // cout<<mp[s[i]];
            }
            mp.clear();
            for(int i=0;i<n;i++){
                if(mp.find(t[i])!=mp.end()){
                    // cout<<mp[s[i]]<<t[i];
                    if(mp[t[i]]!=s[i])
                    {
                        flag2=0;
                        break;
                    }
                }
                mp[t[i]]=s[i];
                // cout<<mp[s[i]];
            }
            if(flag1 && flag2)
                ans.push_back(s);
        }
        return ans;
    }
};