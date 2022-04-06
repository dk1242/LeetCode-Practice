class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=1,c=0,n=nums.size();
        vector<int>lis(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && lis[i]<=lis[j]){
                    lis[i]=lis[j]+1;
                }
            }
            ans=max(ans, lis[i]);
        }
        return ans;
    }
};