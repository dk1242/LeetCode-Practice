class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        int xors=0, all=0;
        for(int i=0;i<=n;i++){
            all^=(i+1);
            // cout<<all;
            if(i<n && i%2){
                xors^=encoded[i];
            }
        }
        // cout<<all<<" "<<xors<<" ";
        vector<int>res;
        int ans=all^xors;
        
        cout<<ans;
        res.push_back(ans);
        for(int i=0;i<n;i++){
            ans^=encoded[i];
            res.push_back(ans);
        }
        return res;
    }
};