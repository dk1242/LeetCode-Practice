class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<32;i++){
            
            // cout<<(1&(c>>i))<<" "<<(1&(a>>i))<<" "<<(1&(b>>i))<<"\n";
            if(1&(c>>i)){
                if(((1&(a>>i))==0) && ((1&(b>>i))==0)){
                    ans++;
                    // cout<<"a";
                }
            }else{
                if((1&(a>>i)) && (1&(b>>i))){
                    ans+=2;
                }else if(1&(a>>i)){
                    ans++;
                }else if(1&(b>>i)){
                    ans++;
                }
            }
            // cout<<ans;
        }
        return ans;
    }
};