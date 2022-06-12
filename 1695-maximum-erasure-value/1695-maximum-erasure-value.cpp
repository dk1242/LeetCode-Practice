class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int>mp;
        int n=nums.size(), ans=0, curr=0,i=0,j=0;
        while(i<n && j<n){
            if(mp[nums[i]]){
                mp[nums[j]]--;
                curr-=nums[j++];
                // ans=max(ans, curr);
            }else{
                curr+=nums[i];
                ans=max(ans, curr);
                mp[nums[i++]]++;
            }
        }
        return ans;
    }
};