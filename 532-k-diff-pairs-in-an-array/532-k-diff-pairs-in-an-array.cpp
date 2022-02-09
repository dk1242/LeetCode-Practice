class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size(), ans=0;
        sort(nums.begin(), nums.end());
        int l=0, r=1;
        while(l<n && r<n){
            if(l==r || nums[r]-nums[l]<k){
                r++;
            }else if(nums[r]-nums[l]>k){
                l++;
            }else{
                l++;
                ans++;
                while(l<n && nums[l]==nums[l-1])
                    l++;
            }
        }
        return ans;
    }
};