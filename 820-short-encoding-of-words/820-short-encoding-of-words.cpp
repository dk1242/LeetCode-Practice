class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string>st;
        int n=words.size();
        for(int i=0;i<n;i++)
            st.insert(words[i]);
        for(auto it:words){
            for(int i=1;i<it.length();i++){
                st.erase(it.substr(i));
            }
        }
        int ans=0;
        for(auto it:st){
            // cout<<it;
            ans+=it.length()+1;
        }
        return ans;
    }
};