class Solution {
public:
    int countHousePlacements(int n) {
        int ans=0;
        int a=1, b=2,c;
        if(n==0)
            return a*a;
        if(n==1)
            return b*b;
        for(int i=2;i<=n;i++){
            c=(a+b)%1000000007;
            a=b,b=c;
        }
        return (1ll*c*c)%1000000007;
    }
};