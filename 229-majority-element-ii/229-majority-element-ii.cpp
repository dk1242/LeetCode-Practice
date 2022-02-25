class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0, c2=0, a=0, b=0;
        for(auto &n:nums){
            if(a==n){
                c1++;
            }else if(b==n){
                c2++;
            }else if(c1==0){
                a=n;
                c1++;
            }else if(c2==0){
                b=n;
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0, c2=0;
        for(auto &n:nums){
            if(a==n)
                c1++;
            else if(b==n) c2++;
        }
        vector<int>res;
        if(c1>nums.size()/3)res.push_back(a);
        if(c2>nums.size()/3)res.push_back(b);
        return res;
    }
};