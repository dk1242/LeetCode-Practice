class Solution {
public:
    void f(vector<int>&cand, int tar, int ind, vector<vector<int>>&res, vector<int>&temp){
        // if(ind==cand.size()){
        //     if(tar==0){
        //         res.push_back(temp);
        //         // return;
        //     }
        //     return;
        // }
        if(tar==0){
            res.push_back(temp);
            return;
        }
        if(tar<0)
            return;
        
        // f(cand, tar, ind+1, res, temp);
        for(int i=ind;i<cand.size();i++){
            temp.push_back(cand[i]);
            f(cand, tar-cand[i], i, res, temp);
            temp.pop_back();        
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<vector<int>>res;
        vector<int>temp;
        vector<vector<int>>memo(cand.size(), vector<int>(tar, -1));
        f(cand, tar, 0, res, temp);
        return res;
    }
};