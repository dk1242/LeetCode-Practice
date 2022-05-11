class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), ans=INT_MIN, temp=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];
            ans=max(ans, temp);
            if(temp<0)
                temp=0;
        }
        return ans;
    }
};