class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int>p2i;
        map<string, int>w2i;
        stringstream ss(s);
        string word;
        int i=0;
        while(ss>>(word)){
            w2i[word]=i++;
        }
        int n=pattern.length();
        for(i=0;i<n;i++){
            p2i[pattern[i]]=i;
        }
        stringstream ss1(s);
        for(i=0;i<n&&ss1>>word;i++){
            if(w2i[word]!=p2i[pattern[i]])
                return false;
        }
        return i==n;
    }
};