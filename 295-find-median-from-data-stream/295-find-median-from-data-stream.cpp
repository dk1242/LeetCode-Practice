class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue <int, vector<int>, greater<int>> right;
    MedianFinder() {
        // nums.resize()
        // this->nums={};
    }
    
    void addNum(int num) {
       if(left.size()==right.size()){
           left.push(num);
           int rt=left.top();
           left.pop();
           right.push(rt);
        }else{
           right.push(num);
           int lt=right.top();
           right.pop();
           left.push(lt);
        }
    }
    
    double findMedian() {
        // cout<<left.size()<<right.size()<<"\n";
        if(left.size()==right.size()){
            // cout<<left.top()<<right.top()<<"\n";
            // cout<<double(left.top()+right.top())/2<<"!";
            return double(left.top()+right.top())/2;
        }else{
            return double(right.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */