class Solution {
public:
    bool backtrack(vector<int>&nums, vector<int>&vis, int target, int curr_sum, int ind, int k){
        if(k==1)
            return true;
        if(ind>=nums.size())
            return false;
        if(curr_sum==target)
            return backtrack(nums, vis, target, 0, 0, k-1);
        for(int j=ind;j<nums.size();j++){
            if(vis[j] || curr_sum+nums[j]>target)
                continue;
            vis[j]=1;
            if(backtrack(nums, vis, target, curr_sum+nums[j], j+1, k))
                return true;
            vis[j]=0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0)
            return false;
        vector<int>vis(nums.size(), 0);
        sort(nums.rbegin(), nums.rend());
        return backtrack(nums, vis, sum/k, 0,0, k);
    }
};