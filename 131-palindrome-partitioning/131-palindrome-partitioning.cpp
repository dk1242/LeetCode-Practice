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
    void f(string s, vector<vector<string>>&ans, vector<string>&res, int ind){
        if(ind==s.length()){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s, ind, i)){
                res.push_back(s.substr(ind, i-ind+1));
                f(s, ans, res, i+1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        f(s, ans, res, 0);
        return ans;
    }
};