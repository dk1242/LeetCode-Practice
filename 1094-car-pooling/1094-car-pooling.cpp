class Solution {
public:
    // static bool comp(vector<int> a, vector<int> b){
    //     return a[1]<b[1];
    // }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int>mp;
        for(auto it:trips){
            mp[it[1]]+=it[0];
            mp[it[2]]-=it[0];
        }
        for(auto it:mp){
            if((capacity-=it.second) < 0){
                return false;
            }
        }
        return true;
        // int n=trips.size();
        // if(n==1){
        //     if(trips[0][0]<=capacity){
        //         return true;
        //     }else return false;
        // }
        // sort(trips.begin(), trips.end(), comp);
        // // for(auto it:trips){
        // //     cout<<it[1]<<" ";
        // // }
        // // cout<<"\n";
        // int left=trips[0][1], right=trips[0][2], curr=trips[0][0];
        // for(int i=1;i<n;i++){
        //     if(trips[i][1]<right){
        //         // cout<<right<<" "<<trips[i][1];
        //         curr+=trips[i][0];
        //         // cout<<curr<<"\n";
        //         if(curr>capacity){
        //             return false;
        //         }
        //         right=min(right, trips[i][2]);
        //     }else{
        //         curr=trips[i][0];
        //         right=trips[i][2];
        //     }
        // }
        // return true;
    }
};