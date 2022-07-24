class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>st;
        int ans=0;
        for(int i=0;i<rolls.size();i++){
            st.insert(rolls[i]);
            if(st.size()==k){
                st.clear();
                ans++;
            }
        }
        return ans+1;
    }
};