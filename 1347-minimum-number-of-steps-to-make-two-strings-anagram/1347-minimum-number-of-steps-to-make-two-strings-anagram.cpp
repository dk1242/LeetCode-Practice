class Solution {
public:
    int minSteps(string s, string t) {
        int mp[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(mp[t[i]-'a']>0){
                mp[t[i]-'a']--;
            }
        }
        int ans=0;
        for(auto it:mp){
            ans+=it;
        }
        return ans;
    }
};