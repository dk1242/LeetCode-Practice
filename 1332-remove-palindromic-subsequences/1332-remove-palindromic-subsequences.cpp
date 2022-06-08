class Solution {
public:
    int removePalindromeSub(string s) {
        string rev=string(s.rbegin(), s.rend());
        if(s==rev)
            return 1;
        else return 2;
    }
};