class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int, int>>arr[128];
        for(int i=0;i<words.size();i++){
            arr[words[i][0]].push_back({i, 1});
        }
        for(auto ch:s){
            auto next=arr[ch];
            arr[ch].clear();
            for(auto it:next){
                arr[words[it.first][it.second++]].push_back(it);
            }
        }
        return arr[0].size();
    }
};