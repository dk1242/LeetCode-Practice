class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int odd=0, ans=0;
        for(auto it:mp){
            ans+=it.second/2*2;
            if(ans%2==0 && it.second%2==1)
                ans++;
        }
        return ans;
    }
};