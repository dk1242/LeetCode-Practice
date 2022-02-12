class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // int n=wordList.size();
        unordered_set<string>dict(wordList.begin(), wordList.end());
        queue<string>q;
        q.push(beginWord);
        int count=1;
        while(!q.empty()){
            // cout<<"\n";
           int n = q.size();
            for(int k=0;k<n;k++){
            string word=q.front();
            q.pop();
            if(word==endWord)
                return count;
            dict.erase(word);
                // cout<<word<<" "<<count<<"->";
            for(int i=0;i<word.length();i++){
                char c=word[i];
                for(int j=0;j<26;j++){
                    word[i]='a'+j;
                    if(dict.find(word)!=dict.end()){
                        // cout<<word<<" ";
                        q.push(word);
                        dict.erase(word);
                    }
                }
                word[i]=c;
            }
                // cout<<" * ";
            }
             count++;
        }
        return 0;
        // unordered_set<string> dict(wordList.begin(), wordList.end());
        // queue<string> todo;
        // todo.push(beginWord);
        // int ladder = 1;
        // while (!todo.empty()) {
        //     int n = todo.size();
        //     for (int i = 0; i < n; i++) {
        //         string word = todo.front();
        //         todo.pop();
        //         if (word == endWord) {
        //             return ladder;
        //         }
        //         dict.erase(word);
        //         for (int j = 0; j < word.size(); j++) {
        //             char c = word[j];
        //             for (int k = 0; k < 26; k++) {
        //                 word[j] = 'a' + k;
        //                 if (dict.find(word) != dict.end()) {
        //                     todo.push(word);
        //                 }
        //              }
        //             word[j] = c;
        //         }
        //     }
        //     ladder++;
        // }
        // return 0;
    }
    
};