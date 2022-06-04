class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(j<2 || nums[i]>nums[j-2]){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};