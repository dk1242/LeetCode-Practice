class Trie{
  public:
    Trie* child[27];
    int index=-1;
};
class WordFilter {
public:
    Trie *trie, *child;
    
    WordFilter(vector<string>& words) {
        int n=words.size();
        trie=new Trie();
        cout<<trie->index;
        for(int i=0;i<n;i++){
            string word=words[i];
            for(int j=0;j<=word.length();j++){
                string str=word.substr(j)+'{'+word;
                // cout<<str<<"\n";
                Trie *obj=trie;
                for(char ch:str){
                    if(obj->child[ch-'a']==NULL){
                        obj->child[ch-'a']=new Trie();
                    }
                    obj=obj->child[ch-'a'];
                    obj->index=i;
                }
            }
        }
        
    }
    
    int f(string pre, string suf) {
        string q=suf+'{'+pre;
        // cout<<q;
        Trie *obj=trie;
        for(char ch:q){
            if(obj->child[ch-'a']==NULL){
                // cout<<"@";
                return -1;
            }
            obj=obj->child[ch-'a'];
        }
        return obj->index;
    }
};

// /**
//  * Your WordFilter object will be instantiated and called as such:
//  * WordFilter* obj = new WordFilter(words);
//  * int param_1 = obj->f(prefix,suffix);
//  */

// class Trie{
//     public:
//     Trie * child[27];
//     int index = -1;
// };

// class WordFilter {
// public:
//     Trie * trie, *child;
//     void insertTrie(string word, int pos){
//         int index;
//         Trie * obj  = trie;
//         for(char ch: word){
//             index  = ch - 'a';
//             auto it = obj->child[index];
//             if(it==NULL){
//                 child = new Trie();
//                 obj->child[index] = child;
//             }
//             obj = obj->child[index];
//             obj->index = pos;
//         }
//     }
    
//     int searchTrie(string word) {
//         int index;
//         Trie * obj  = trie;
//         cout<<word;
//         for(char ch: word){
//             index  = ch - 'a';
//             if(obj->child[index]==NULL) return -1;
//             obj = obj->child[index];
//         }
        
//         return obj->index;
//     }
    
//     WordFilter(vector<string>& words) {
//         int n = words.size();
//         trie = new Trie();
//         for(int i=0;i<n;i++){
//             for(int j=0; j<words[i].length();j++){
//                 string str = words[i].substr(j) + "{" + words[i];
//                 cout<<str<<" ";
//                 insertTrie(str,i);        
//             }    
//         }
//     }
    
//     int f(string prefix, string suffix) {
//         return searchTrie(suffix + "{" + prefix);
//     }
// };