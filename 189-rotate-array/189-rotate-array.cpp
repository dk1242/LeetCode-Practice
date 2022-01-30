class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1)
            return;
        k=k%n;
        int start=0, end=n-k-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start=n-k, end=n-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start=0, end=n-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
};