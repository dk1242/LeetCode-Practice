class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size(), ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<nums
                if(j==i)continue;
                 // cout<<i<<" "<<j<<" "<<nums[i]+nums[j]<<"\n";
                if(nums[i]+nums[j]==target)
                    {
                   // ;
                    ans++;}
            }
        }
        return ans;
    }
};