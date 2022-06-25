class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int ans=0;
        for(int i=0;i<n;i++)
            ans=ans|nums[i];
        return ans;
    }
};