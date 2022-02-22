class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        for(int i=0;i<22;i++){
            cout<<(1&(num>>i));
            if((1&(num>>i))){
                ans+=2;
            }else ans++;
            
            if((num>>(i+1))==0)
                break;
        }
        cout<<"\n";
        return ans-1;
    }
};