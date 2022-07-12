class Solution {
public:
    int backtrack(vector<string>&words, vector<int>&freq, vector<int>&score, int ind){
        int ans=0;
        if(ind==words.size())return ans;
        for(int i=ind; i<words.size();i++){
            int res=0;
            int isValid=1;
            for(char ch:words[i]){
                freq[ch-'a']--;
                res+=score[ch-'a'];
                if(freq[ch-'a']<0){isValid=0; }
            }
            if(isValid){
                res+=backtrack(words, freq, score, i+1);
                ans=max(ans, res);
            }
            for(char ch:words[i]){
                freq[ch-'a']++;
            }
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26, 0);
        for(auto ch:letters){
            freq[ch-'a']++;
        }
        return backtrack(words, freq, score, 0);
    }
};