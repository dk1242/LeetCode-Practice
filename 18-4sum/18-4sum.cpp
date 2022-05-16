class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t=target-nums[i]-nums[j];
                int l=j+1, r=n-1;
                while(l<r){
                    if(nums[l]+nums[r]==t){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        res.push_back(temp);
                        while(l<r && nums[l]==temp[2])l++;
                        while(l<r && nums[r]==temp[3])r--;
                        
                    }else if(nums[l]+nums[r]<t){
                        l++;
                    }else r--;
                }
                while(j+1<n && nums[j+1]==nums[j])j++;
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return res;
    }
};