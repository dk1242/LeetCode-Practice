class Solution {
public:
    bool isPalindrome(string s, int l, int h){
      while(l<h){
          if(s[l++]!=s[h--]){
              return false;
          }
      }
      return true;
    }
    void allpart(vector<vector<string>>&all, vector<string>&curr, int start, int n, string s){
        if(start>=n){
            all.push_back(curr);
            return;
        }
        for(int i=start;i<n;i++){
            if(isPalindrome(s, start, i)){
                curr.push_back(s.substr(start, i-start+1));
                allpart(all, curr, i+1, n, s);
                curr.pop_back();
            }
        }
    }    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> all;
        vector<string> curr;
        allpart(all, curr, 0, n, s);
        return all;
    }
};