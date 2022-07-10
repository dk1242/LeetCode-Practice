class Solution {
public:
    void count(vector<char>&v, int i, int cur, int &ans, int n){
        if(cur==n){
            ans++;
            return;
        }
        for(int j=i;j<5;j++){
            count(v, j, cur+1, ans, n);;
        }
    }
    int countVowelStrings(int n) {
        int ans=0;
        vector<char>v={'a', 'e', 'i', 'o', 'u'};
        count(v, 0, 0, ans, n);
        return ans;
    }
};