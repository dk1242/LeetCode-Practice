class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int count=0, ans=0;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end())
            while(st.find(nums[i]++)!=st.end()){
                count++;
            }
            
                ans=max(ans, count);
                count=0;
            
        }
        return ans;
    }
};