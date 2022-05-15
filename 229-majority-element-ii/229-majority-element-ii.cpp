class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0, c2=0, a,b;
        for(auto it:nums){
            if(it==a){
                c1++;
            }else if(it==b){
                c2++;
            }else if(c1==0){
                a=it;
                c1++;
            }else if(c2==0){
                b=it;
                c2++;
            }else {
                c1--, c2--;
            }
        }
        c1=0, c2=0;
        for(auto it:nums){
            if(it==a)
                c1++;
            else if(it==b)
                c2++;
        }
        vector<int>res;
        if(c1>nums.size()/3)res.push_back(a);
        if(c2>nums.size()/3)res.push_back(b);
        return res;
    }
};