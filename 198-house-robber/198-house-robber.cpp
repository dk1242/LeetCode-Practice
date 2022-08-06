class Solution {
public:
    int f(vector<int>&nums, int i, vector<int>&memo){
        if(i<0){
            return 0;
        }
        if(memo[i]!=-1)
            return memo[i];
        return memo[i]=max(nums[i]+f(nums, i-2, memo), f(nums, i-1, memo));
    }
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(), -1);
        return f(nums, nums.size()-1, memo);
    }
};