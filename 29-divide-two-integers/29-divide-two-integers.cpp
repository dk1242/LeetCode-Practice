class Solution {
public:
    int divide(int dd, int ds) {
        bool isNeg=(dd<0 && ds>0) || (dd>0 && ds<0);
        long long res=0, temp, count;
        long long dd1=abs(dd), ds1=abs(ds);
        while(dd1>=ds1){
            temp=ds1, count=1;
            // cout<<temp;
            while(temp*2<=dd1){
                temp*=2;
                count*=2;
            }
            res+=count;
            dd1-=temp;
        }
        if(isNeg)
            res*=-1;
        if(res>INT_MAX)
            res=INT_MAX;
        return res;
    }
};