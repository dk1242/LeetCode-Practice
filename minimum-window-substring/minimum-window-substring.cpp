class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int counter=t.size(), i=0, j=0, l=0, r=INT_MAX;
        while(i<s.size()){
            if(mp[s[i++]]-->0)
                counter--;
            while(counter==0){
                if(i-j<r-l){
                    r=i, l=j;
                }
                if(mp[s[j++]]++==0)
                    counter++;
            }
        }
        return r==INT_MAX?"":s.substr(l, r-l);
    }
};