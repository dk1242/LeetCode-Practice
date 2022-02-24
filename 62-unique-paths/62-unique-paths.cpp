class Solution {
public:
    int findUniquePaths(int i, int j, int m, int n, unordered_map<string, int> &mp){
        string key=to_string(i)+","+to_string(j);
        if(mp.find(key) != mp.end())
            return mp[key];
        if(i==m || j==n){
            return mp[key]=1;
        }
        if(i>m || j>n)
            return mp[key]=0;
        return mp[key]=findUniquePaths(i+1, j, m, n, mp)+findUniquePaths(i, j+1, m, n, mp);
        
    }
    
    unordered_map<string, int>mp;
    int uniquePaths(int m, int n) {
        return findUniquePaths(1, 1, m, n, mp);
        // string key=to_string(m)+","+to_string(n);
        // if(mp.find(key) != mp.end())
        //     return mp[key];
        // if(m==1 || n==1){
        //     return mp[key]=1;
        // }
        // // if(m<=0 || n<=0)
        // //     return mp[key]=0;
        // return mp[key]=uniquePaths(m-1, n)+uniquePaths(m, n-1);
    }
};