class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int ans=0, n=s.length();
        int i=0,j=0;
        while(i<n && j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j++]);
                ans=max(ans, j-i);
            }else{
                st.erase(s[i++]);
            }
        }
        return ans;
    }
};