class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        multiset<int, greater<int>>mst;
        
        for(int i=0;i<k;i++){
            mst.insert(nums[i]);
        }
        auto it=mst.begin();
        res.push_back(*it);
        for(int i=k;i<nums.size();i++){
            auto it=mst.find(nums[i-k]);
            mst.erase(it);
            mst.insert(nums[i]);
            res.push_back(*mst.begin());
        }
        return res;
    }
};