class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0, prod=1;
        for(int l=0,r=0;r<n;r++){
            prod*=nums[r];
            while(l<=r && prod>=k){
                prod/=nums[l++];
            }
            // cout<<l<<" "<<r<<"\n";
            ans+=(r-l+1);
        }
        return ans;
    }
};