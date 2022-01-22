class Solution {
public: 
    unordered_map<int, bool>mp;
    bool dfs(int remain){
        if(mp[remain]){
            return mp[remain];
        }
        int sqrt_root = sqrt(remain);
        for(int i=1; i<=sqrt_root; i++){
            // cout<<mp[remain]<<' ';
            if(dfs(remain-(i*i))==false){
                return mp[remain]=true;
            }
        }
        return mp[remain]=false;
    }
    bool winnerSquareGame(int n) {
        // mp[0]=false, mp[1]=true;
        // return dfs(n);
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};