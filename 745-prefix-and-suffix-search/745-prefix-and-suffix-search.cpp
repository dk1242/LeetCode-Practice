// class Trie{
//   public:
//     TrieNode
// };
class WordFilter {
public:
    unordered_map<string, int>mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            string word=words[i];
            for(int j=1;j<=word.length();j++){
                string p=word.substr(0,j);
                for(int k=0;k<word.length();k++){
                    string s=word.substr(k, word.length());
                    // cout<<p<<" "<<s<<" "<<i+1<<"\n";
                    mp[p+'|'+s]=i+1;
                }
            }
        }
        
    }
    
    int f(string pre, string suf) {
        string q=pre+'|'+suf;
        return mp[q]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */