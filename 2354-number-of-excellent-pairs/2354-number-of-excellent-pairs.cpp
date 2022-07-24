class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long freq[33]={0};
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int ones=0;
            if(i>0 && nums[i]==nums[i-1])continue;
            // for(int j=0;j<32;j++){
            //     if(((nums[i]>>j)&1) == 1){
            //         ones++;
            //     }
            //     if(nums[i]>>j <= 0)
            //         break;
            // }
            // cout<<ones<<" ";
            freq[__builtin_popcount(nums[i])]++;
        }
        long long ans=0;
        for(int i=1;i<30;i++){
            for(int j=1;j<30;j++){
                if(i+j>=k){
                    // cout<<i<<j<<"@";
                    ans+=freq[i]*freq[j];
                }
            }
        }
        return ans;
    }
};