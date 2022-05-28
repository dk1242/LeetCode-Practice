class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=nums[0], n=nums.size();
        for(int i=1;i<n;i++){
            ans^=nums[i];
        }
        for(int i=0;i<=n;i++)
            ans^=i;
        return ans;
    }
};