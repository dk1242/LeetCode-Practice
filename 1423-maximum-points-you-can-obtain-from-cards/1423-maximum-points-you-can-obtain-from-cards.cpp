class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n=cards.size();
        int i=0,j=n-k;
        int sum=0, ans=0;
        for(int i=j;i<n;i++)
            sum+=cards[i];
        ans=sum;
        while(k--){
            ans=max(ans, sum+=cards[i++]-cards[j++]);
        }
        return ans;
    }
};