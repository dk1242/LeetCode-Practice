class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0, diff=INT_MAX;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int targ=target-nums[i];
            int front=i+1;
            int back=n-1;
            while(front<back){
                int sum=nums[front]+nums[back];
                
                if(sum<targ){
                    front++;
                    if(abs(sum+nums[i]-target)<diff){
                        diff=abs(sum+nums[i]-target);
                        ans=sum+nums[i];
                    }
                }else if(sum>targ){
                    back--;
                    if(abs(sum+nums[i]-target)<diff){
                        diff=abs(sum+nums[i]-target);
                        ans=sum+nums[i];
                    }
                }else{
                    return target;
                }
            }
            // while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};