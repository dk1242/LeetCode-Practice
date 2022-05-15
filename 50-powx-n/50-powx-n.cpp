class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || x==0)
            return x;
        // int f=0;
        // if(n<0){
        //     f=1;
        //     n*=-1;
        // }
        // cout<<n;
        double res=1.0;
        while(n!=0){
            if(n&1){
                res=n>0?res*x:res/x;;
            }
            n=n/2;
            x*=x;
        }
        return res;
    }
};