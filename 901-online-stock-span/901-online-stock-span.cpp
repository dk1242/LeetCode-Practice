class StockSpanner {
public:
    stack<pair<int, int>>st;
    int maxm, curr;
    StockSpanner() {
        maxm=INT_MIN;
        curr=0;
    }
    
    int next(int price) {
        int res=1;
        while(!st.empty() && st.top().first<=price){
            res+=st.top().second;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */