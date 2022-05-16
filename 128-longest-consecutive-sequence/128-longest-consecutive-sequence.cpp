class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &it:nums)
            st.insert(it);
        int ans=0;
        for(auto &it:nums){
            if(st.find(it-1)==st.end()){
                int curr=it, len=1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
                ans=max(ans, len);
            }
        }
        return ans;
    }
};