class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        for(int i=0;i<=e;i++){
            if(nums[i]==0){
                swap(nums[s++], nums[i]);
                // i--;
            }else if(nums[i]==2){
                swap(nums[e--], nums[i--]);
                // if(nums[i]!=0)
                //     i--;
                // i--;
            }
            // for(int j=0;j<n;j++)cout<<nums[j]<<" ";
            // cout<<"\n";
        }
    }
};