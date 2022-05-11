class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=0, f=0;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                ind=i-1;
                f=1;
                break;
            }
        }
        if(f==0 && ind==0){
            sort(nums.begin(),nums.end());
            return;
        }
        int end=n-1;
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                end=i;
                break;
            }
        }
        // cout<<ind<<end;
        // for(int i=ind;i<end;i++){
            swap(nums[ind], nums[end]);
        // }
        reverse(nums.begin()+ind+1, nums.end());
    }
};