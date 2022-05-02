class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int a=0, b=n-1;
        while(a<b){
            if(nums[a]%2>nums[b]%2){
                swap(nums[a], nums[b]);
            }
            if(nums[a]%2==0)a++;
            if(nums[b]%2==1)b--;
        }
        return nums;
    }
};