class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>>vp;
        vector<int>v;
        map<int, vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int sum=0;
            while(temp>0){
                sum+=temp%10;
                temp/=10;
            }
            vp.push_back({sum, nums[i]});
        }
        sort(vp.begin(), vp.end());
        int ans=-1;
        for(int i=1;i<vp.size();i++){
            if(vp[i].first==vp[i-1].first){
                ans=max(ans, vp[i].second+vp[i-1].second);    
            }
        }
        return ans;
    }
};