class Solution {
public:
    int find1st(vector<int>& nums, int target){
        int ind=-1;
        int l=0, r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]<=target){
                l=m+1;
            }else r=m-1;
            if(nums[m]==target)ind=m;
        }
        return ind;
    }
    int find2nd(vector<int>& nums, int target){
        int ind=-1;
        int l=0, r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]>=target){
                r=m-1;
            }else l=m+1;
            if(nums[m]==target)ind=m;
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        res[1]=find1st(nums, target);
        res[0]=find2nd(nums, target);
        return res;
    }
};