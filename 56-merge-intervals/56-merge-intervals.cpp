class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<n;i++){
            if(res.size()==0){
                res.push_back(intervals[i]);
            }else{
                if(res.back()[1]>=intervals[i][0]){
                    res.back()[1]=max(intervals[i][1], res.back()[1]);
                }else{
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};