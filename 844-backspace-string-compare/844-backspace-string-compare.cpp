class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                a+=s[i];
            }else if(a!="")a.pop_back();
        }
        // int n=s.length(), m=t.length();
        // if(s[n-1]!='#'){
        //     a+=s[n-1];
        // }
        
        for(int i=0;i<t.length();i++){
            if(t[i]!='#'){
                b+=t[i];
            }else if(b!="")b.pop_back();
        }
        // if(t[m-1]!='#'){
        //     b+=s[m-1];
        // }
        if(a==b)
            return true;
        else return false;
    }
};