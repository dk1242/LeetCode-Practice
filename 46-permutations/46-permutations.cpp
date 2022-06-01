class Solution {
public:
    void backtrack(vector<vector<int>>&res, vector<int>&nums, int n, int start){
        if(start==n-1){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[i], nums[start]);
            backtrack(res, nums, n, start+1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        backtrack(res, nums, n, 0);
        return res;
    }
};