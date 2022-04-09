class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x: nums) m[x]++;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto x: m) {
            pq.push({x.second, x.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        // map<int, int>mp;
        // for(auto it:nums){
        //     mp[it]++;
        // }
        // vector<int>res;
        // vector<pair<int, int>>vp;
        // for(auto it:mp){
        //     vp.push_back({it.second, it.first});
        // }
        // sort(vp.rbegin(), vp.rend());
        // for(auto &it:vp){
        //     // cout<<it.first<<it.second<<" ";
        //     if(k--){
        //         res.push_back(it.second);
        //     }else break;
        // }
        // return res;
    }
};