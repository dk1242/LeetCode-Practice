class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        vector<int>height,width;
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        height.push_back(hCuts[0]);
        int n=hCuts.size();
        for(int i=1;i<n;i++){
            height.push_back(hCuts[i]-hCuts[i-1]);
        }
        height.push_back(h-hCuts[n-1]);
        
        width.push_back(vCuts[0]);
        int m=vCuts.size();
        for(int i=1;i<m;i++){
            width.push_back(vCuts[i]-vCuts[i-1]);
        }
        width.push_back(w-vCuts[m-1]);
        int max1=*max_element(height.begin(), height.end());
        int max2=*max_element(width.begin(), width.end());
        return 1ll*max1*max2%1000000007;
        // return 1;
    }
};