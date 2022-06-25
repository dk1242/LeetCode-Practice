class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char>st;
        int open=0,close=0;
        for(char& c: s) {
            if(c=='('){
                // st.push(c);
                open++;
            }
            // else if(!st.empty() && st.top()=='('){
            //     st.pop();
            // }else st.push(c);
            else if(open>0){
                open--;
            }else close++;
        }
        // return st.size();
        return open+close;
    }
};