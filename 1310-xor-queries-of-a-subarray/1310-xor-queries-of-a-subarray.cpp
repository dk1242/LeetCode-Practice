class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size(), q=queries.size();
        vector<int>xors;
        xors.push_back(arr[0]);
        for(int i=1;i<n;i++){
            xors.push_back(xors[i-1]^arr[i]);
        }
        vector<int>ans;
        for(int i=0;i<q;i++){
            int a=queries[i][0], b=queries[i][1];
            if(queries[i][0]==0){
                ans.push_back(xors[b]);
            }else{
                ans.push_back(xors[b]^xors[a-1]);
            }
        }
        return ans;
    }
};