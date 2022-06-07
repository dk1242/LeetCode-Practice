class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // map<int, vector<int>>mp;
        int m=edges.size();
        set<int>st;
        for(int i=0;i<m;i++){
            st.insert(edges[i][1]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!st.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};