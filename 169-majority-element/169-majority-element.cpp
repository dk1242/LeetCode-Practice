class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count=0;
        for(auto it:nums){
            if(count==0){
                ans=it;
            }
            if(it==ans){
                count++;
            }else count--;
        }
        return ans;
    }
};