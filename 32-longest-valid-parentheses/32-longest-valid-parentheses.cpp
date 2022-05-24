class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int n=s.length();
        // vector<int>dp(n, 0);
        // for(int i=1;i<n;i++){
        //     if(s[i]==')'){
        //         if(s[i]=='('){
        //             dp[i]=(i>=2 ? dp[i-2] : 0)+2;
        //         }else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
        //             dp[i]=dp[i-1]+((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0)+2;
        //         }
        //         ans=max(ans, dp[i]);
        //     }
        // }
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else ans=max(ans, i-st.top());
            }
        }
        return ans;
    }
};