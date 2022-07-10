class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int up=1,down=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])up=down+1;
            else if(nums[i]<nums[i-1]) down=up+1;
        }
        // if(nums[n-1]==nums[n-2])ans--;
        return max(up, down);
    }
};