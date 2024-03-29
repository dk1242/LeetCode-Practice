class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // vector<pair<int, int>>vp;
        // for(int i=0;i<arr.size();i++){
        //     vp.push_back({abs(arr[i]-x), arr[i]});
        // }
        // sort(vp.begin(), vp.end());
        // vector<int>ans(k,0);
        // for(int i=0;i<k;i++){
        //     ans[i]=vp[i].second;
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
        int lo=0, hi=arr.size()-k, mid;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                lo=mid+1;
            }else hi=mid;
        }
        // cout<<lo<<hi<<"\n";
        return vector<int>(arr.begin()+lo, arr.begin()+lo+k);
    }
};