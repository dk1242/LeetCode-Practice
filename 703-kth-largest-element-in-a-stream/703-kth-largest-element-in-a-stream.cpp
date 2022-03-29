class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        // this->pq=priority_queue<int>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        // cout<<pq.top();
        pq.push(val);
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */