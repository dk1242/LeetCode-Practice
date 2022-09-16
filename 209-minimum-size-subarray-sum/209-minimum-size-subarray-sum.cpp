class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        int sum=0, ans=INT_MAX;
        while(j<n){
            sum+=nums[j++];
            while(sum>=tar){
                sum-=nums[i++];
                ans=min(ans, j-i+1);
            }
        }
        if(ans==INT_MAX)
            return 0;
        else return ans;
    }
};