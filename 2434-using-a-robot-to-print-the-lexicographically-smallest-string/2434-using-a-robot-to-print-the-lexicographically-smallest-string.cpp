class Solution {
public:
    string robotWithString(string s) {
        map<char, int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string t, p;
        int lo=0;
        for(auto ch:s){
            t+=ch;
            mp[ch]--;
            while(lo<26 && mp[lo+'a']==0){
                lo++;
            }
            while(!t.empty() && t.back()-'a'<=lo){
                p+=t.back();
                t.pop_back();
            }
        }
        return p;
    }
};