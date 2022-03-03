class Solution {
public:
    string getPermutation(int n, int k) {
        // string a;
        // for(int i=0;i<n;i++){
        //     a+=to_string(i+1);
        // }
        // while(--k){
        //     next_permutation(a.begin(), a.end());
        // }
        // return a;
        int fact=1;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
            fact*=(i+1);
        }
        fact/=n;
        string ans="";
        k--;
        while(1){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(!nums.size())
                break;
            k=k%fact;
            fact/=nums.size();
        }
        return ans;
    }
};