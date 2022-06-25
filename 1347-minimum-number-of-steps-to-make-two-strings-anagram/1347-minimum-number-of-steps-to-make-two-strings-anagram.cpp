class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[t[i]]>0){
                mp[t[i]]--;
            }
        }
        int ans=0;
        for(auto it:mp){
            ans+=it.second;
        }
        return ans;
    }
};