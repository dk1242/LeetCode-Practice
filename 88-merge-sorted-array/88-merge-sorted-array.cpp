class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=m-1, k=n-1, i=0;
        for(i=n+m-1;k>=0 && j>=0 && i>=0;i--){
            cout<<i;
            if(nums1[j]<=nums2[k]){
                nums1[i]=nums2[k--];
            }else{
                nums1[i]=nums1[j--];
            }
            // for(int l=0;l<nums1.size();l++)
            //     cout<<nums1[l]<<" ";
            // cout<<"\n";
        }
        if(k>=0){
            for(;i>=0 && k>=0;i--){
                nums1[i]=nums2[k--];
            }
        }
        
        if(j>=0){
            for(;i>=0 && j>=0;i--){
                nums1[i]=nums1[j--];
            }
        }
    }
};