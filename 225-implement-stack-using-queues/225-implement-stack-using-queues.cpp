class MyStack {
public:
    queue<int>q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            // cout<<q2.front();
            q1.pop();
        }
        int tmp=q1.front();
        q1.pop();
        swap(q1, q2);
        // cout<<tmp;
        return tmp;
    }
    
    int top() {
        if(!q1.empty())
            return q1.back();
        return -1;
    }
    
    bool empty() {
        return q1.empty();
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