class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int bitallow=0;
        for(auto ch:allowed){
            bitallow|=1<<(ch-'a');
        }
        // cout<<bitallow<<"\n";
        int ans=0;
        for(int i=0;i<words.size();i++){
            int bitword=bitallow;
            for(auto ch:words[i]){
                bitword|=1<<(ch-'a');
            }
            // cout<<bitword<<" ";
            if((bitallow^bitword) ==0){
                ans++;
            }
        }
        return ans;
    }
};