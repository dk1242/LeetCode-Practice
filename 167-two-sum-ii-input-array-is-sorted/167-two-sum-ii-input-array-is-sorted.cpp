class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int n=nums.size();
        int front=0;
            int back=n-1;
            while(front<back){
                int sum=nums[front]+nums[back];
                
                if(sum<target){
                    front++;
                }else if(sum>target){
                    back--;
                }else{
                    res.push_back(front+1);
                    res.push_back(back+1);
                    return res;
                }
            }
        return res;
    }
};