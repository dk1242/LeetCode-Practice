class Solution {
public:
    double myPow(double x, long long n) {
        if(x==1 || x==0)
            return x;
        int f=0;
        if(n<0){
            f=1;
            n*=-1;
        }
        double res=1.0;
        while(n>0){
            if(n&1){
                res*=x;
            }
            n=n>>1;
            x*=x;
        }
        if(f)
            return 1/res;
        return res;
    }
};