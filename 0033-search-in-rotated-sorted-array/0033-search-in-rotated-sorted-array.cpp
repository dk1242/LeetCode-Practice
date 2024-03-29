class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>nums[r]){
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }else l=mid+1;
            }else if(nums[mid]<nums[l]){
                if(nums[mid]<target && target<nums[l]){
                    l=mid+1;
                }else r=mid-1;
            }else{
                if(nums[mid]<target){
                    l=mid+1;
                }else r=mid-1;
            }
        }
        return -1;
    }
};