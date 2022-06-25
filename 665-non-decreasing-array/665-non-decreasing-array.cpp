class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1, prev=nums[0];i<n;i++){
            // cout<<prev<<" "<<nums[i-1]<<"\n";
            if(prev>nums[i]){
                if(c++)
                    return false;
                // if(i-2>=0 && nums[i-2]>nums[i])
                //     nums[i]=nums[i-1];
                // else nums[i-1]=nums[i];
                
                if(i-2>=0 && nums[i-2]>nums[i])
                    continue;
            }
            prev=nums[i];
        }
        return true;
    }
};