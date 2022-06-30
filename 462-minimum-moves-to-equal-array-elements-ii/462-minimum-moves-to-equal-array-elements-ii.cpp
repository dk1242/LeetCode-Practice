class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sum=0;
        sort(nums.begin(), nums.end());
        int mid=nums[nums.size()/2];
        int ans=0;
        for(int i:nums){
            ans+=abs(i-mid);
        }
        return ans;
    }
};