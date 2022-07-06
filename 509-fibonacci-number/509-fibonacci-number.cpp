class Solution {
public:
    int fib(int n) {
        int a=0, b=1;
        if(n==0)
            return a;
        if(n==1)
            return b;
        int c;
        while(n-->=2){
            c=b+a;
            a=b, b=c;
        }
        return b;
    }
};