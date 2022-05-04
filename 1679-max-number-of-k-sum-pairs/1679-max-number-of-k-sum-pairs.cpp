class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        // sort(nums.begin(), nums.end());
        // int i=0, j=n-1,c=0;
        // while(i<j){
        //     if(nums[i]+nums[j]==k){
        //         c++;
        //         i++, j--;
        //     }else if(nums[i]+nums[j]<k){
        //         i++;
        //     }else j--;
        // }
        // return c;
        int ans=0;
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]>k)
                continue;
            mp[nums[i]]++;
            if(mp[k-nums[i]]>0 && k-nums[i]!=nums[i]){
                mp[nums[i]]--;
                mp[k-nums[i]]--;
                ans++;
            }
            if(k-nums[i]==nums[i] && mp[nums[i]]>1){
                mp[nums[i]]--;
                mp[k-nums[i]]--;
                ans++;
            }
        }
        return ans;
    }
};