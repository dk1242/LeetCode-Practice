class Solution {
public:
    // int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end){
    //     if(end-begin<=1)
    //         return 0;
    //     auto mid = begin + (end - begin) / 2;
    //     int count=sort_and_count(begin, mid)+sort_and_count(mid, end);
    //     for(auto i=begin, j=mid; i!=mid;i++){
    //         while(j!=end && *i>2ll* *j){
    //             ++j;
    //         }
    //         count+=j-mid;
    //     }
    //     inplace_merge(begin, mid, end);
    //     return count;
    // }
    void checkCount(vector<int>&nums, int start, int mid, int end, int &count){
        int l=start, r=mid+1;
        while(l<=mid && r<=end){
            if(nums[l]>2ll*nums[r]){
                count+=(mid-l+1);
                r++;
            }else{
                l++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return;
    }
    void mergeSort(vector<int>& nums, int start, int end, int &count){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums,start, mid, count);
        mergeSort(nums,mid+1,end, count);
        
        checkCount(nums,start,mid,end, count);
    }
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        int count = 0;
        mergeSort(nums,0,nums.size()-1, count);
        return count;
    }
};