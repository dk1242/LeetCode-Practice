class Solution {
public:
    void f(vector<int>&cand, int tar, int ind, vector<vector<int>>&res, vector<int>&temp){
        if(ind==cand.size()){
            if(tar==0){
                res.push_back(temp);
                // return;
            }
            return;
        }
        if(tar<0)
            return;
        if(tar==0){
            res.push_back(temp);
            return;
        }
        f(cand, tar, ind+1, res, temp);
        temp.push_back(cand[ind]);
        f(cand, tar-cand[ind], ind, res, temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<vector<int>>res;
        vector<int>temp;
        f(cand, tar, 0, res, temp);
        return res;
    }
};