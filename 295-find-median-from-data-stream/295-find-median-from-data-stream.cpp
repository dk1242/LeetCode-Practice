class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue <int, vector<int>, greater<int>> right;
    MedianFinder() {
        // nums.resize()
        // this->nums={};
    }
    
    void addNum(int num) {
       if(left.empty() && right.empty()){
           right.push(num);
       }else{
           if(num<=right.top()){
               left.push(num);
           }else right.push(num);
           if(left.size()-right.size()==2){
               right.push(left.top());
               left.pop();
           }else if(right.size()-left.size()==2){
               left.push(right.top());
               right.pop();
           }
       }
    }
    
    double findMedian() {
        // cout<<left.size()<<right.size()<<"\n";
        if(left.size()==right.size()){
            // cout<<left.top()<<right.top()<<"\n";
            // cout<<double(left.top()+right.top())/2<<"!";
            return double(left.top()+right.top())/2;
        }else{
            if(right.size()>left.size())
            return double(right.top());
            else return  double(left.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */