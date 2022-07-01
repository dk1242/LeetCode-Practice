class Solution {
public:
    int numSplits(string s) {
        unordered_set<char>st1, st2;
        int n=s.length();
        vector<int>left(n,0), right(n,0);
        for(int i=0;i<n;i++){
            st1.insert(s[i]);
            left[i]=st1.size();
        }
        for(int i=n-1;i>=0;i--){
            st2.insert(s[i]);
            right[i]=st2.size();
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(left[i]==right[i+1])ans++;
        }
        return ans;
    }
};