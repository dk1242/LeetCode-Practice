class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl=s.length(), tl=t.length();
        int i=0,j=0;
        if(sl==0){
            return true;
        }
        while(i<sl && j<tl){
            if(s[i]==t[j]){
                
                if(i==sl-1){
                    return true;
                }
                i++,j++;
            }else{
                j++;
            }
        }
        return false;
    }
};