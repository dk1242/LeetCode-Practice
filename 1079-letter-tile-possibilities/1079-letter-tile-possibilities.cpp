class Solution {
public:
    int res=0;
    void calc(int count[26]){
        for(int i=0;i<26;i++){
            if(count[i]){
                count[i]--;
                res++;
                calc(count);
                count[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int count[26]={0};
        for(auto c:tiles){
            count[c-'A']++;
        }
        calc(count);
        return res;
    }
};