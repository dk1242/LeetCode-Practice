class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, ans;
        for(auto it:nums){
            if(count==0){
                ans=it;
            }
            if(it==ans)
                count++;
            else count--;
        }
        return ans;
    }
};