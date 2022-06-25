class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])
                if(c++ || i>1 && i<n-1 && nums[i-2]>nums[i] && nums[i+1]<nums[i-1])
                    return false;
        }
        return true;
    }
};