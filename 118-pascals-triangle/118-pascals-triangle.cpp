class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>res;
        for(int i=0;i<n;i++){
            res.insert(res.begin(), 1);
            for(int j=1;j<res.size()-1;j++){
                res[j]=res[j]+res[j+1];
            }
            ans.push_back(res);
        }
        return ans;
    }
};