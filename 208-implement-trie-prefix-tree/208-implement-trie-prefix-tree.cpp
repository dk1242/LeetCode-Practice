class Trie {
public:
    int we;
    Trie* child[26];
    Trie() {
        for(int i=0;i<26;i++)
            child[i]=NULL;
        we=0;
    }
    
    void insert(string word) {
        Trie* curr = this;
        int n=word.length();
        for(int i=0;i<n;i++){
            char ch=word[i]-'a';
            if(!curr->child[ch]){
                curr->child[ch]=new Trie();
            }
            curr=curr->child[ch];
        }
        curr->we=1;
    }
    
    bool search(string word) {
        Trie* curr = this;
        int n=word.length();
        for(int i=0;i<n;i++){
            int ch=word[i]-'a';
            if(!curr->child[ch])
                return false;
            curr=curr->child[ch];
        }
        return curr->we;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        int n=prefix.length();
        for(int i=0;i<n;i++){
            int ch=prefix[i]-'a';
            if(!curr->child[ch])
                return false;
            curr=curr->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */