class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto &it:nums){
            if(pq.size()<k){
                pq.push(it);
            }else{
                // cout<<pq.top();
                if(pq.top()<it){
                    pq.pop();
                    pq.push(it);
                }
                // cout<<pq.top()<<"\n";
            }
        }
        return pq.top();
    }
};