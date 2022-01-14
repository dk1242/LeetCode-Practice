class Solution {
public:
    int myAtoi(string s) {
        long long i=0,ans=0, sign=1;
        while(s[i]==' ')i++;
        if(s[i]=='-'){
            sign=-1;i++;}
        else if(s[i]=='+'){
            sign=1;i++;}
        while(s[i]>='0' && s[i]<='9'){
            //cout<<ans;
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]-'0'>7)){
                if(sign==-1)
                    return INT_MIN;
                else return INT_MAX;
            }
            ans=ans*10+s[i++]-'0';
        }
        return ans*sign;
    }
};