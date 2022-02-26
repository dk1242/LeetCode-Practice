class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int target1=target-nums[i];
            for(int j=i+1;j<n;j++){
                int target2=target1-nums[j];
                int front=j+1, back=n-1;
                while(front<back){
                    int sum=nums[front]+nums[back];
                    // cout<<sum;
                    if(sum==target2){
                        // cout<<sum;
                        vector<int>ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[front]);
                        ans.push_back(nums[back]);
                        res.push_back(ans);
                        while(front<back && nums[front]==ans[2])front++;
                        while(front<back && nums[back]==ans[3])back--;
                    }else if(sum<target2){
                        front++;
                    }else back--;
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return res;
    }
};