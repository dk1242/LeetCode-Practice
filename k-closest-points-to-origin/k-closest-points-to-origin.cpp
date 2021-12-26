class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<double, vector<int>>mp;
        int n=points.size();
        for(int i=0;i<n;i++){
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            mp.insert({sqrt(dist), points[i]});
        }
        vector<vector<int>>res;
        // for(auto it:mp){
        //     cout<<it.first<<" ";
        // }
        // cout<<"\n";
        for(auto it:mp){
            if(k-->0)
            res.push_back(it.second);
            else break;
        }
        return res;
    }
};