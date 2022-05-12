class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minm=INT_MAX, ans=0;
        for(int i=0;i<n;i++){
            minm=min(minm, prices[i]);
            ans=max(ans, prices[i]-minm);
        }
        return ans;
    }
};