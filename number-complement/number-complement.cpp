class Solution {
public:
    int findComplement(long long num) {
        long long n;
        // if(num==INT_MAX)
        //     return 0;
        n=log2(num);
        cout<<n<<"\n";
        // n=n<<1;
        // n=n-1;
        long long n2=pow(2, n+1)-1;
        cout<<n2<<"\n";
        return num^n2;
    }
};