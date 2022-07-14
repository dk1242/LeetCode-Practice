class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<int>&sats, int i, int time){
        if(i>=sats.size())
            return 0;
        if(dp[i][time]!=-1)
            return dp[i][time];
        int ans1=sats[i]*time + dfs(sats, i+1, time+1);
        int ans2=dfs(sats, i+1, time);
        return dp[i][time]=max({0, ans1, ans2});
    }
    int maxSatisfaction(vector<int>& sats) {
        // dp.resize(sats.size()+1, vector<int>(sats.size()+1, -1));
        sort(sats.rbegin(), sats.rend());
        // return dfs(sats, 0, 1);
        int n=sats.size();
        int sum=0;
        vector<int>pre;
        for(int i=0;i<n;i++){
            sum+=sats[i];
            if(sum<0)
                break;
            pre.push_back(sats[i]);
        }
        reverse(pre.begin(), pre.end());
        sum=0;
        for(int i=0;i<pre.size(); i++){
            sum+=(i+1)*pre[i];
        }
        return sum;
    }
};