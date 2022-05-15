class Solution {
public:
    int countPairs(vector<int>&nums, int l, int mid, int r){
        int count=0;
        int s1=l, s2=mid+1;
        while(s1<=mid && s2<=r){
            if(nums[s1]>2ll*nums[s2]){
                count+=mid-s1+1;
                s2++;
            }else s1++;
        }
        sort(nums.begin()+l, nums.begin()+r+1);
        return count;
    }
    int mergeSort(vector<int>&nums, int l, int r){
        if(l==r){
            return 0;
        }
        int mid=(l+r)/2;
        int ans=0;
        ans+=mergeSort(nums, l, mid);
        ans+=mergeSort(nums, mid+1, r);
        ans+=countPairs(nums, l, mid, r);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};