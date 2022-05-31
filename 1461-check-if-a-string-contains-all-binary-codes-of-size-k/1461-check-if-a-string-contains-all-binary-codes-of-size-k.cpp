class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<int,int>mp;
        int n=s.length();
        for(int i=0;i<n-k+1;i++){
            string sub=s.substr(i, k);
            long num=stol(sub,0,2);
            mp[num]++;
        }
        for(int i=0;i<pow(2, k);i++){
            if(mp[i]==0)
                return false;
        }
        return true;
    }
};