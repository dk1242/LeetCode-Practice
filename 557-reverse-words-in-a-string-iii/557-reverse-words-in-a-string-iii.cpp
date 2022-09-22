class Solution {
public:
    string reverseWords(string s) {
        int t=0, p=0, n=s.length();
        for(int i=0;i<n;i++){
            t++;
            if(s[t]==' '||i==n-1){
                reverse(s.begin()+p, s.begin()+t);
                p=t+1;
            }
        }
        return s;
    }
};