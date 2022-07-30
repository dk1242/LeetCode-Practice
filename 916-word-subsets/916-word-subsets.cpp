class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size(), m=words2.size();
         vector<int>count(26, 0);
        int i;
        for(string a : words2){
            vector<int>curr(26);
            // curr.resize(26, 0);
            for(char c:a){
                curr[c-'a']++;
            }
            for(int i=0;i<26;i++){
                count[i]=max(count[i], curr[i]);
            }
        }
        vector<string> res;
        for (string a : words1) {
            // curr.resize(26, 0);
            vector<int>curr(26);
            for(char c:a){
                curr[c-'a']++;
            }
        // for(int i=0;i<26;i++)cout<<curr[i];
        //     cout<<"\n";
            for (i = 0; i < 26; ++i)
                if (curr[i] < count[i])
                    break;
            if (i == 26) res.push_back(a);
        }
        return res;
    }
};