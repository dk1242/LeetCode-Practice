class Solution {
public:
    bool canBrk(int start, unordered_set<string> &uset, string &s, vector<int>&mem){
        if(start==s.length())return 1;
        if(mem[start]!=-1)
            return mem[start];
        string sub;
        for(int i=start; i<s.length(); i++){
            if(uset.count(sub+=s[i]) && canBrk(i+1, uset, s, mem)){
                return mem[start]=1;
            }
        }
        return mem[start]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        // for(auto it:uset){
        //     cout<<it<<" ";
        // }
        vector<int> mem(s.size(), -1);
        bool ans = canBrk(0, uset, s, mem);
        for(auto it:mem){
            cout<<it;
        }
        return ans;
    }
};