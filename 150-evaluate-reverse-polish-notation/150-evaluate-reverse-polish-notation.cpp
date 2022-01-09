class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(it=="+"||it=="/"||it=="-"||it=="*"){
                int t1=st.top();
                st.pop();
                int t,t2=st.top();
                if(it=="/")
                    t=t2/t1;
                else if(it=="*")
                    t=t2*t1;
                else if(it=="+")
                    t=t2+t1;
                else t=t2-t1;
                st.pop();
                // cout<<t1<<it<<t2<<" "<<t<<"\n";
                st.push(t);
            }else{
                int t=stoi(it);
                // cout<<t<<" ";
                st.push(t);
            }
        }
        return st.top();
    }
};