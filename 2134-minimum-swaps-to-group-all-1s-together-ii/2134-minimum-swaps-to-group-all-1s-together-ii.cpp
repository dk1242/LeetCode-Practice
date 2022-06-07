class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=count(nums.begin(), nums.end(), 1);
        if(ones<=1)
            return 0;
        int k=ones;
        int maxOnes=0;
        int cnt=0;
        for(int i=0;i<k;i++)
            if(nums[i]==1)cnt++;
        maxOnes=cnt;
        for(int i=k;i<n+k;i++){
            if(nums[i-k])cnt--;
            if(nums[i%n])cnt++;
            maxOnes=max(maxOnes, cnt);
        }
        return k-maxOnes;
    }
};