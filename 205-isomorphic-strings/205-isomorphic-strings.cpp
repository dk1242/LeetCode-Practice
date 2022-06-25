class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                // cout<<mp[s[i]]<<t[i];
                if(mp[s[i]]!=t[i])
                return false;
            }
            mp[s[i]]=t[i];
            // cout<<mp[s[i]];
        }
        mp.clear();
        for(int i=0;i<n;i++){
            if(mp.find(t[i])!=mp.end()){
                // cout<<mp[s[i]]<<t[i];
                if(mp[t[i]]!=s[i])
                return false;
            }
            mp[t[i]]=s[i];
            // cout<<mp[s[i]];
        }
        return true;
    }
};