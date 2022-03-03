class Solution {
public:
    void backtrack(vector<vector<int>>&res, vector<int>&res1, vector<int>&nums, int n, int start){
        if(start==n){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[start], nums[i]);
            backtrack(res, res1, nums, n, start+1);
            swap(nums[start], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>res1;
        int n=nums.size();
        backtrack(res, res1, nums, n, 0);
        return res;
    }
};