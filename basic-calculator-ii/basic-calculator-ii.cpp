class Solution {
public:
    int calculate(string s) {
        int l=s.length();
        if(l==0)
            return 0;
        stack<int>st;
        long long currNum=0;
        char currOp='+';
        for(int i=0;i<l;i++){
            if(isdigit(s[i])){
                currNum=currNum*10+s[i]-'0';
            }
            if(!isdigit(s[i]) && !iswspace(s[i])||i==l-1){
                if(currOp=='-'){
                    st.push(-currNum);
                }else if(currOp=='+'){
                    st.push(currNum);
                }else if(currOp=='*'){
                    int sTop=st.top();
                    st.pop();
                    st.push(sTop*currNum);
                }else if(currOp=='/'){
                    int sTop=st.top();
                    st.pop();
                    st.push(sTop/currNum);
                }
                currOp=s[i];
                currNum=0;
            }
        }
        long long res=0;
        while(st.size()!=0){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};