class Solution {
public:
    bool detectCapitalUse(string word) {
        int l=word.length(), c=0;
        for(int i=0;i<l;i++){
            if(word[i]>='A' && word[i]<='Z'){
                c++;
            }
        }
        if(c==1){
            if(word[0]>='A' && word[0]<='Z')
                return true;
            else
                return false;
        }else if(c==l || c==0)
           return true;
           else return false;
    }
};