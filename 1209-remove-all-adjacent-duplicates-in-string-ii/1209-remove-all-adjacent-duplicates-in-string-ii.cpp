class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        vector<int> mp(n, 1);
        stack<int>st;
        string ans;
        st.push(0);
        for(int i=1;i<n;i++){
            if(!st.empty()){
                if(s[st.top()]==s[i]){
                    mp[i]=mp[st.top()]+1;
                }
            }
            st.push(i);
            if(mp[st.top()]==k){
                for(int i=0;i<k;i++){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans+=s[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};