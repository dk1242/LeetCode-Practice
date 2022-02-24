class Solution {
public:
    double myPow(double x, long long n) {
      double res=1.0;
        int f=0;
        if(n<0){
            n*=-1;
            f=1;
        }
        while(n>0){
            if(n&1){
                res*=x;
            }
            n=n>>1;
            x*=x;
        }
        if(f==1)
            return 1/res;
        return res;
    }
};