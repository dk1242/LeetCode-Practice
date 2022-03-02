class Solution {
public:
    void backtrack(vector<int>&res1, vector<int>&candidates, int target, set<vector<int>>&ans, int start){
        if(target==0){
            // cout<<"@";
            vector<int>temp=res1;
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            // res1.clear();
            return;
        }
        if(target<0){
            // res1.pop_back();
            return;
        }
        int n=candidates.size();
        // cout<<start<<"-";
        for(int i=start;i<n;i++){
            if(i>start && candidates[i]==candidates[i-1])continue;
            // cout<<i<<" ";
            // if(target<candidates[i])break;
            res1.push_back(candidates[i]);
            backtrack(res1, candidates, target-candidates[i], ans, i+1);
            res1.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<vector<int>>res;
        vector<int>res1;
        // cout<<candidates.size();
        sort(candidates.begin(), candidates.end());
        backtrack(res1, candidates, target, ans, 0);
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};