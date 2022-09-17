class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        int curr, minm;
        for(int p:{1, -1}){
            for(int q:{1, -1}){
                minm=p*arr1[0]+q*arr2[0]+0;
                for(int i=1;i<arr1.size();i++){
                    curr=p*arr1[i]+q*arr2[i]+i;
                    ans=max(ans, curr-minm);
                    minm=min(minm, curr);
                }
            }
        }
        return ans;
    }
};