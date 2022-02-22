class Solution {
public:
    void backtrack(int start, vector<vector<int>>&ans, vector<int>&res, vector<int>& nums){
        // if(nums.size()==k){
            ans.push_back(res);
        // }
        for(int i=start; i<nums.size(); i++){
            res.push_back(nums[i]);
            backtrack(i+1, ans, res, nums);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>res;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(1&(i>>j)){
                    res.push_back(nums[j]);
                }
            }
            ans.push_back(res);
            res.clear();
        }
        return ans;
    }
};