class Solution {
public:
    void backtrack(vector<int>&res1, vector<int>&candidates, int target, vector<vector<int>>&ans, int start){
        if(target==0){
            // vector<int>temp=res1;
            // sort(temp.begin(), temp.end());
            ans.push_back(res1);
            // res1.clear();
            return;
        }
        if(target<0){
            // res1.pop_back();
            return;
        }
        int n=candidates.size();
        for(int i=start;i<n;i++){
            res1.push_back(candidates[i]);
            backtrack(res1, candidates, target-candidates[i], ans, i);
            res1.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // set<vector<int>>res;
        // sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>res1;
        backtrack(res1, candidates, target, ans, 0);
        // for(auto it:res){
        //     ans.push_back(it);
        // }
        return ans;
    }
};