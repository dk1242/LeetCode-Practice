class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        int i=0, j=n-1,ans=0,score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                score++;
            }else if(ans>0){
                power+=tokens[j--];
                score-=1;
            }else break;
            ans=max(ans, score);
        }
        return ans;
    }
};