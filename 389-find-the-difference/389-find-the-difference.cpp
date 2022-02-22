class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=t[s.size()];
        for(int i=0;i<s.length();i++){
           ans^=s[i]^t[i];
        }
        return ans;
    }
};