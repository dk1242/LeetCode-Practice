class Solution {
public:
    string getPermutation(int n, int k) {
        string a;
        for(int i=0;i<n;i++){
            a+=to_string(i+1);
        }
        while(--k){
            next_permutation(a.begin(), a.end());
        }
        return a;
    }
};