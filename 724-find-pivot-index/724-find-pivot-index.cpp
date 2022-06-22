class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        // vector<int>left(n,0), right(n,0);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long leftsum=0;
        for(int i=0;i<n;i++){
            if(leftsum==sum-leftsum-nums[i])
                return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};