class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n, 0);
        vis[0]=1;
        stack<int>st;
        st.push(0);
        while(!st.empty()){
            int r=st.top();
            st.pop();
            for(auto it:rooms[r]){
                if(vis[it]==0){
                    vis[it]=1;
                    st.push(it);
                }
            }
        }
        for(auto it:vis){
            // cout<<it;
            if(!it)return false;
        }
        return true;
    }
};