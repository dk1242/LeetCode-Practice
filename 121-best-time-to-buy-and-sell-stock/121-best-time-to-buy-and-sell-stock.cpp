class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0,minp=INT_MAX, maxp=INT_MIN;
        for(int i=0; i<n; i++){
            minp=min(minp, prices[i]);
            
            ans=max(ans, prices[i]-minp);
        }
        return ans;
    }
};