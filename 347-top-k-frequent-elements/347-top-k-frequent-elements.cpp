class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>res;
        vector<pair<int, int>>vp;
        for(auto it:mp){
            vp.push_back({it.second, it.first});
        }
        sort(vp.rbegin(), vp.rend());
        for(auto &it:vp){
            // cout<<it.first<<it.second<<" ";
            if(k--){
                res.push_back(it.second);
            }else break;
        }
        return res;
    }
};