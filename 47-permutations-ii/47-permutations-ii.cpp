class Solution {
public:
    void backtrack(set<vector<int>>&res, vector<int>&nums, int n, int start){
        if(start==n-1){
            res.insert(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[i], nums[start]);
            backtrack(res, nums, n, start+1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>res;
        vector<vector<int>>ans;
        int n=nums.size();
        backtrack(res, nums, n, 0);
        for(auto it:res)ans.push_back(it);
        return ans;
    }
};