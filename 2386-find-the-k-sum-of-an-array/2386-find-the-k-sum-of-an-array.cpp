class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                sum+=nums[i];
            }else nums[i]*=-1;
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<long long, long long>>pq;
        pq.push({sum-nums[0], 0});
        long long ans=0;
        while(--k){
            auto it=pq.top();
            pq.pop();
            ans=it.first;
            if(it.second<nums.size()-1){
                // cout<<it.first<<" ";
                pq.push({ans-nums[it.second+1], it.second+1});
                pq.push({ans-nums[it.second+1]+nums[it.second], it.second+1});
            }
            sum=ans;
            // cout<<sum<<" ";
        }
        // cout<<sum<<"@";
        return sum;
    }
};