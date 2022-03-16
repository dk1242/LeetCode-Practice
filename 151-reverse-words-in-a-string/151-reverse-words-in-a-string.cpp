class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        int n=s.length();
        // cout<<n;
        int c=1;
        string ans="";
        // int i=0, j=n-1;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else if(s[i]==' ' && temp!=""){
                // cout<<ans;
                if(ans!="")
                ans=temp+" "+ans;
                else ans=temp;
                temp="";
            }
            // cout<<temp;
        }
        if(temp!=""){
            if(ans!="")
            ans=temp+" "+ans;
            else ans=temp;
        }
        return ans;
    }
};