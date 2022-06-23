class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.length();
        vector<int>ans(m, 0);
        for(int i=0;i<m;i++){
            int x=startPos[0], y=startPos[1];
            for(int j=i;j<m;j++){
                if(s[j]=='R'){
                    y++;
                }else if(s[j]=='L'){
                    y--;
                }else if(s[j]=='U'){
                    x--;
                }else{
                    x++;
                }
                if(min(x,y)<0 || max(x,y)>=n){
                    break;
                }else{
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};