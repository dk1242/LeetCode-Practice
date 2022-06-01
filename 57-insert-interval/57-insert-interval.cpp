class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInt) {
        int n=intervals.size(), i=0;
        vector<vector<int>>res;
        while(i<n && intervals[i][1]<newInt[0]){
            res.push_back(intervals[i++]);
        }
        while(i<n && intervals[i][0]<=newInt[1]){
            newInt[0]=min(newInt[0], intervals[i][0]);
            newInt[1]=max(newInt[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInt);
        while(i<n)res.push_back(intervals[i++]);
        return res;
    }
};