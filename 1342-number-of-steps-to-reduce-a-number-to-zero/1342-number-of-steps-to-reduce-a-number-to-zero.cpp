class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        for(int i=0;i<22;i++){
            if((1&(num>>i))){
                ans+=2;
            }else ans++;
            
            if((num>>(i+1))==0)
                break;
        }
        return ans-1;
    }
};