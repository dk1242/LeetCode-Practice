class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), beg=-1, end=-2, minm=nums[n-1], maxm=nums[0];
        for(int i=1;i<n;i++){
            minm=min(minm, nums[n-i-1]);
            maxm=max(maxm, nums[i]);
            if(nums[i]<maxm) end=i;
            if(nums[n-1-i]>minm) beg=n-i-1;
        }
        return end-beg+1;
    }
};