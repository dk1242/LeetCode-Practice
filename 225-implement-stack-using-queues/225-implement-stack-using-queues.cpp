class MyStack {
public:
    queue<int>q1, q2;
    stack<int>st;
    MyStack() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int t;
        if(!st.empty()){
            t=st.top();
            st.pop();
        }
        else t=-1;
        return t;
        
    }
    
    int top() {
        if(!st.empty())
            return st.top();
        return -1;
    }
    
    bool empty() {
        // cout<<st.top();
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */