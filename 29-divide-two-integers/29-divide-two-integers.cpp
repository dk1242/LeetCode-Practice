class Solution {
public:
    int divide(int dd, int ds) {
        // bool isNeg=(dd<0 && ds>0) || (dd>0 && ds<0);
        // long long res=0, temp, count;
        // long long dd1=abs(dd), ds1=abs(ds);
        // while(dd1>=ds1){
        //     temp=ds1, count=1;
        //     // cout<<temp;
        //     while(temp<=dd1){
        //         temp*=2;
        //         count*=2;
        //     }
        //     res+=count/2;
        //     dd1-=temp/2;
        // }
        // if(isNeg)
        //     res*=-1;
        // if(res>INT_MAX)
        //     res=INT_MAX;
        // return res;
        long long t=0, q=0, n=labs(dd), m=labs(ds);
        int sign = (dd<0) ^ (ds<0) ? -1 : 1;
        for(long long i=31;i>=0;i--)
        {
			//(m<<i) = m * (2^i)
            if(t + (m<<i) <= n)
            {
                t += (m<<i);
				
				//since 2^i here can be large for int so we typecast it in long long to prevent overflow 
                q += (1LL<<i);
            }
        }
        cout<<q;
        if(sign<0) q=-q;
        return ((q>INT_MAX) or (q<INT_MIN)) ? INT_MAX : q;
    }
};