class Solution {
public:
    
    void count(vector<char>&v, int i, int cur, int &ans, int n){
        if(cur==n){
            ans++;
            return;
        }
        for(int j=i;j<5;j++){
            count(v, j, cur+1, ans, n);;
        }
    }
    int countVowelStrings(int n) {
        int ans=0;
        // vector<char>v={'a', 'e', 'i', 'o', 'u'};
        vector<int>dp(5, 1);
        while(n-->1){
            for(int i=3;i>=0;i--){
                dp[i]+=dp[i+1];
            }
        }
        ans=accumulate(dp.begin(), dp.end(),0);
        return ans;
    }
};